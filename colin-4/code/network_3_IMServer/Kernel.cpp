#include"Kernel.h"
#include"mediator/TcpServerMediator.h"
#include"net/def.h"
// 静态成员变量类外初始化
Kernel* Kernel::pKernel = nullptr;

// Kernel构造函数
Kernel::Kernel() {
	setProtocolArry();
	pKernel = this;
	m_pMediator = new TcpServerMediator;
}

// Kernel析构函数
Kernel::~Kernel() {

}

// 打开服务端
bool Kernel::startServer() {
	//打开网络
	if (!m_pMediator->openNet()) {
		cout << "打开网络失败." << endl;
		return false;
	}
	//连接数据库
	char ip[] = "127.0.0.1";
	char name[] = "root";
	char pass[] = "ljp26214.";
	char db[] = "20250319im";
	if (!m_sql.ConnectMySql(ip,name,pass,db)) {
		cout << "连接数据库失败." << endl;
		return false;
	}
	return true;
}

// 关闭服务端
void Kernel::closeServer() {
	//关闭网络
	if (m_pMediator) {
		
		m_pMediator->closeNet();
		delete m_pMediator;
		m_pMediator = nullptr;
	}
	//断开数据库
	m_sql.DisConnect();
}

//  初始化函数指针数组
void Kernel::setProtocolArry() {
	//1.初始化数组,把空间写成空
	memset(m_arrFun, 0, sizeof(m_arrFun));

	//2.把函数地址存入数组
	m_arrFun[DEF_PROT_REGISTER_RQ - DEF_PROT_BASE] = &Kernel::dealRegisterRq;
	m_arrFun[DEF_PROT_LOGIN_RQ - DEF_PROT_BASE] = &Kernel::dealLoginRq;
	m_arrFun[DEF_PROT_ADD_FRIEND_OFFLINE - DEF_PROT_BASE] = &Kernel::dealOfflineRq;
	m_arrFun[DEF_PROT_CHAT_INFO_RQ - DEF_PROT_BASE] = &Kernel::dealChatRq;
	m_arrFun[DEF_PROT_ADD_FRIEND_RQ - DEF_PROT_BASE] = &Kernel::dealAddFriendRq;
	m_arrFun[DEF_PROT_ADD_FRIEND_RS - DEF_PROT_BASE] = &Kernel::dealAddFriendRs;

}

// 分发处理所有接收到的数据
void Kernel::dealData(char* data, int len, long from) {
	// 1.取出结构体中的协议类型
	prot_type type = *(prot_type*)data;
	// 2.根据协议类型判断走哪个处理函数
	// 计算数组下标
	int index = type - DEF_PROT_BASE;
	// 判断数组下标是否在有效范围内
	if (index >= 0 && index <= DEF_PROT_COUNT) {
		//根据数组下标取出函数地址
		PFUN p = m_arrFun[index];
		//判断指针是否为空
		if (p) {
			(this->*p)(data, len, from);
		}
		else {
			cout << "index:" << index << endl;
			cout << "type2:" << type << endl;
		}
	}else {
		cout << "type1:" << type << endl;
	}
}

// 处理注册请求
void Kernel::dealRegisterRq(char* data, int len, long from) {
	cout << __func__ << endl;
	// 1.拆包
	PROT_REGISTER_RQ* rq = (PROT_REGISTER_RQ*)data;
	// 打印接收到的结构体内容
	cout << "rq->nick:" << rq->nick << "rq->pass:" << rq->pass << "rq->tel:" << rq->tel << endl;

	
	// 2.判断手机号是否被注册过(
	// 根据手机号查询用户信息表,如果查询结果不为空,说明未注册过
	list<string> lstStr;
	char sqlBuf[1024] = "";
	sprintf_s(sqlBuf, "select tel from t_user where tel = '%s';", rq->tel);
	if (!m_sql.SelectMySql(sqlBuf,1, lstStr)) {
		//只要数据库连接成功,操作数据库失败的原因只有sql语句不对:把日志里的sql拷贝到workebench里面执行
		cout << "查询数据库失败:"<< sqlBuf <<endl;
		return;
	}

	PROT_REGISTER_RS rs;
	// 判断查询结果是否为空,不为空就是被注册过
	if (lstStr.size()!= 0) {
		// 如果被手机号注册过，注册失败
		rs.result = REGISTER_RESULT_FAIL_TEL;
	}
	else {
		// 如果手机号未被注册,判断昵称是否被注册
		// 根据手机号查询用户信息表,如果查询结果不为空,说明未注册过
		sprintf_s(sqlBuf, "select name from t_user where name = '%s';", rq->nick);
		if (!m_sql.SelectMySql(sqlBuf, 1, lstStr)) {
			//只要数据库连接成功,操作数据库失败的原因只有sql语句不对:把日志里的sql拷贝到workebench里面执行
			cout << "查询数据库失败:" << sqlBuf << endl;
			return;
		}
		if (lstStr.size() != 0) {
			//如果昵称被注册过,注册失败
			rs.result = REGISTER_RESULT_FAIL_NAME;
		}
		else {
			//如果昵称未被注册,开始注册(把用户写入数据库)
			sprintf_s(sqlBuf, 
				"insert into t_user (name,tel,pass,feeling,iconid) values ('%s','%s','%s','东北雨姐真真带派！','3');"
				, rq->nick,rq->tel,rq->pass);

			if (!m_sql.UpdateMySql(sqlBuf)) {
				//只要数据库连接成功,操作数据库失败的原因只有sql语句不对:把日志里的sql拷贝到workebench里面执行
				cout << "插入数据库失败:" << sqlBuf << endl;
				return;
			}
			//注册成功
			rs.result = REGISTER_RESULT_SUCC;
		}
	}
	//给客户端回一个注册回复
	m_pMediator->sendData((char*)&rs, sizeof(rs), from);
}

// 处理登录请求
void Kernel::dealLoginRq(char* data, int len, long from) {
	cout << __func__ << endl;
	//1.拆包
	PROT_LOGIN_RQ* rq = (PROT_LOGIN_RQ*)data;
	// 打印接收到的结构体内容
	cout << "rq->pass:" << rq->pass << "rq->tel:" << rq->tel << endl;

	//2.判断用户是否注册过
	//根据手机号查询用户信息表，如果查询结果为空，就是未注册
	list<string> lstStr;
	char sqlBuf[1024] = " ";
	sprintf_s(sqlBuf, " select pass, id from t_user where tel = '%s';", rq->tel);
	PROT_LOGIN_RS rs;
	if (!m_sql.SelectMySql(sqlBuf, 2, lstStr)) {
		//查询结果为空登陆失败，未注册
		cout << "查询用户登录信息失败" << sqlBuf << endl;
		return;
	}
	if (lstStr.size() == 0) {
		rs.result = LOGIN_RESULT_NOEXIST;
	}
	else {
		//查询结果不为空，比较查询出来的密码和本次输入的密码是否相同
		//从list中取出密码
		string pass = lstStr.front();
		lstStr.pop_front(); //把取出的数据从list删除
		//从list中取出id
		int id = stoi(lstStr.front());
		lstStr.pop_front();
		//比较两个密码是否相同
		if (pass == rq->pass) {
			//密码相同，登陆成功
			rs.userid = id;
			rs.result = LOGIN_RESULT_SUCC;

			//给客户端回一个登录回复
			m_pMediator->sendData((char*)&rs, sizeof(rs), from);

			// 保存当前登录的客户端的用户id和socket
			m_mapIdToSocket[id] = from;

			// 根据自己的id获取自己的信息和好友的信息
			getUserInfoAndFriendInfo(id);


			return;
		}
		else {
			//密码不同，登陆失败，密码错误
			rs.result = LOGIN_RESULT_PASSERR;
		}
	}

	//给客户端回一个登录回复
	m_pMediator->sendData((char*)&rs, sizeof(rs), from);
}

// 根据自己的id获取自己的信息和好友的信息
void Kernel::getUserInfoAndFriendInfo(int id)
{
	cout << __func__ << endl;
	// 根据自己的id查询自己的信息
	PROT_FRIEND_INFO userInfo = {};
	getInfoById(id, &userInfo);

	// 把自己的信息发回给客户端(发给当前登录的用户)
	if (m_mapIdToSocket.count(id) > 0) {
		m_pMediator->sendData((char*)&userInfo, sizeof(userInfo), m_mapIdToSocket[id]);
	}
	else {
		cout << "把自己的信息发回给客户端" << id << endl;
	}

	// 根据自己的id查询好友的id列表
	list<string> lstStr;
	char sqlBuf[1024] = " ";
	sprintf_s(sqlBuf, " select idB from t_friend where idA = '%d';", id);
	PROT_LOGIN_RS rs;
	if (!m_sql.SelectMySql(sqlBuf, 1, lstStr)) {
		cout << "查询数据库失败:" << sqlBuf << endl;
		return;
	}

	// 遍历好友id列表
	int friendId = 0;
	PROT_FRIEND_INFO friendInfo = {};
	while (lstStr.size() > 0/*list的size不为空*/) {
		// 取出当前好友的id，取完数据要从list中删除
		friendId = stoi(lstStr.front());
		lstStr.pop_front();

		// 根据好友的id查询好友的信息
		getInfoById(friendId, &friendInfo);

		// 把好友的信息发回给客服端
		if (m_mapIdToSocket.count(id) > 0) {
			m_pMediator->sendData((char*)&friendInfo, sizeof(friendInfo), m_mapIdToSocket[id]);
		}
		else {
			cout << "把好友的信息发回给客户端" << id << endl;
		}

		// 判断好友是否在线，在线就通知(把自己的信息发给好友)
		if (m_mapIdToSocket.count(friendId) > 0) {
			m_pMediator->sendData((char*)&userInfo, sizeof(userInfo), m_mapIdToSocket[friendId]);
		}

	}

}

// 根据id查询用户信息
void Kernel::getInfoById(int id, PROT_FRIEND_INFO* info)
{
	cout << __func__ << endl;
	info->friendid = id;
	// 判断用户是否在线（看map中是否有用户的id）
	if (m_mapIdToSocket.count(id) > 0) {
		// map中有就是在线
		info->status = FRIEND_STATUS_ONLINE;
	}
	else {
		info->status = FRIEND_STATUS_OFFLINE;
	}
	// 根据用户id查询当前用户的昵称，签名和头像id
	list<string> lstStr;
	char sqlBuf[1024] = " ";
	sprintf_s(sqlBuf, " select name, feeling, iconid from t_user where id = '%d';", id);
	PROT_LOGIN_RS rs;
	if (!m_sql.SelectMySql(sqlBuf, 3, lstStr)) {
		cout << "查询数据库失败" << sqlBuf << endl;
		return;
	}

	// 从查询结果在中取出数据
	if (3 == lstStr.size()) {
		// 取出昵称
		strcpy_s(info->nick, lstStr.front().c_str());
		lstStr.pop_front();
		// 取出签名
		strcpy_s(info->feeling, lstStr.front().c_str());
		lstStr.pop_front();
		// 取出头像id
		info->iconid = stoi(lstStr.front());
		lstStr.pop_front();
	}
	else {
		cout << "从数据库中查询当前用户的昵称，签名和头像id:" << sqlBuf << endl;
	}
}

// 处理下线请求
void Kernel::dealOfflineRq(char* data, int len, long from)
{
	cout << __func__ << endl;
	//1.拆包
	PROT_FRIEND_OFFLINE* rq = (PROT_FRIEND_OFFLINE*)data;
	// 2.根据下线用户的id查询好友id的列表
	list<string> lstStr;
	char sqlBuf[1024] = " ";
	sprintf_s(sqlBuf, " select idB from t_friend where idA = '%d';", rq->offuserid);
	PROT_LOGIN_RS rs;
	if (!m_sql.SelectMySql(sqlBuf, 1, lstStr)) {
		cout << "查询数据库失败:" << sqlBuf << endl;
		return;
	}

	// 遍历好友id列表
	int friendId = 0;
	while (lstStr.size() > 0/*list的size不为空*/) {
		// 取出当前好友的id，取完数据要从list中删除
		friendId = stoi(lstStr.front());
		lstStr.pop_front();

		// 根据好友id判断好友是否在线，只通知在线好友
		if (m_mapIdToSocket.count(friendId) > 0)
		{
			// 把下线请求结构体发给好友
			m_pMediator->sendData(data, len, m_mapIdToSocket[friendId]);
		}
	}

	// 回收下线用户的资源
	// 找到map中的下线用户的socket，关闭套接字
	auto ite = m_mapIdToSocket.find(rq->offuserid);
	if (ite != m_mapIdToSocket.end()) {
		closesocket(ite->second);
	}

	// 把无效节点从map中移除
	m_mapIdToSocket.erase(ite);
}

// 处理聊天请求
void Kernel::dealChatRq(char* data, int len, long from)
{
	cout << __func__ << endl;
	//拆包
	PROT_CHAT_INFO_RQ* rq = (PROT_CHAT_INFO_RQ*)data;

	//判断好友是否在线
	if (m_mapIdToSocket.count(rq->friendid) > 0)
	{
		//好友在线，把聊天请求转发给好友
		m_pMediator->sendData(data, len, m_mapIdToSocket[rq->friendid]);

	}
	else
	{
		//好友不在线，给发起聊天的用户回复不在线
		PROT_CHAT_INFO_RS rs;
		rs.friendid = rq->myid;
		rs.myid = rq->friendid;
		rs.result = CHAT_RESULT_FAIL;
		m_pMediator->sendData((char*)&rs, sizeof(rs), from);
	}
	//实际：好友不在线，先把A跟B的聊天信息保存到数据库当中
	//等B登录成功的时候，从数据库中查询到A发给B的聊天内容，转发给B，同时从数据库中删除
}

// 处理添加好友请求
void Kernel::dealAddFriendRq(char* data, int len, long from)
{
	cout << __func__ << endl;
	// 拆包
	PROT_ADD_FRIEND_RQ* rq = (PROT_ADD_FRIEND_RQ*)data;

	// 判断B用户是否存在
	// 根据B用户的昵称查询数据库
	list<string> lstStr;
	char szSql[1024] = "";
	sprintf_s(szSql, "select id from t_user where name = '%s';", rq->frinick);
	if (!m_sql.SelectMySql(szSql, 1, lstStr))
	{
		cout << "查询数据库失败:" << szSql << endl;
		return;
	}

	PROT_ADD_FRIEND_RS rs;

	// 判断查询结果是否在空
	if (0 == lstStr.size()) {
		// 查询结果为空，说明B不存在，添加失败，ADD_FRIEND_NOEXIST
		rs.result = ADDFRI_RESULT_NOEXIST;
		strcpy_s(rs.mynick, sizeof(rs.mynick), rq->frinick);
		// 把添加结果返回给A
		m_pMediator->sendData((char*)&rs, sizeof(rs), from);
		return;
	}
	else {
		//取出B用的id
		int friendId = stoi(lstStr.front());
		lstStr.pop_front();
		// 查询结果不为空，查看B用户是否在线
		if (m_mapIdToSocket.count(friendId) > 0) {
			// B用户在线，把添加好友请求转发给B
			m_pMediator->sendData(data, len, m_mapIdToSocket[friendId]);
		}
		else {
			// B不在线，添加失败，ADD_FRIEND_OFFLINE
			rs.result = ADDFRI_RESULT_OFFLINE;

			strcpy_s(rs.mynick, sizeof(rs.mynick), rq->frinick);
			// 把添加结果返回给A
			m_pMediator->sendData((char*)&rs, sizeof(rs), from);
		}
	}
}

//处理添加好友回复
void Kernel::dealAddFriendRs(char* data, int len, long from) {
	cout << __func__ << endl;
	// 拆包
	PROT_ADD_FRIEND_RS* rs = (PROT_ADD_FRIEND_RS*)data;

	//判断是否同意添加，同意把两个人关系结果写入数据库，更新双端好友列表
	if (ADDFRI_RESULT_ACCEPT == rs->result) {
		char sqlBuf[1024] = " ";
		//string str;
		sprintf_s(sqlBuf, " insert into t_friend values(%d,%d);", rs->destid, rs->myid);
		if (!m_sql.UpdateMySql(sqlBuf)) {
			//只要数据库连接成功，操作数据库失败的原因只有sql语句不对：把日志里的sql拷贝到workbanch里执行
			cout << "插入数据库失败" << sqlBuf << endl;
			return;
		}
		sprintf_s(sqlBuf, " insert into t_friend values(%d,%d);", rs->myid, rs->destid);
		if (!m_sql.UpdateMySql(sqlBuf)) {
			//只要数据库连接成功，操作数据库失败的原因只有sql语句不对：把日志里的sql拷贝到workbanch里执行
			cout << "插入数据库失败" << sqlBuf << endl;
			return;
		}
		//更新双端信息
		getUserInfoAndFriendInfo(rs->myid);
	}
	//把结果告诉客户端A
	if (m_mapIdToSocket.count(rs->destid) > 0) {
		m_pMediator->sendData(data, len, m_mapIdToSocket[rs->destid]);
	}
}
