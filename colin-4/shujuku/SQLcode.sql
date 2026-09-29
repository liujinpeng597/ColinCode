#注意：
#1.注释#号
#2.sql语句以；为接尾
#3.当查询默认使用的库中的表时，不用指定库名

#运行sql语句：
#闪电带光标：运行光标所在行的sql语句
#闪电：1.先选中几条sql语句，全部运行alter
#2.不选中，就是从上到下执行当前文件中所有的sql语句，如果中途有报错就停止。

#设置默认使用的库
use 20250319text;

#创建表table
#create table 表名（列名1 数据类型 建表约束，列表2 数据类型 建表约束，...）;

#数据类型
#char(15):一个字符占1个字节，固定长度是15，例如“hello world”,实际存储“hello world0000”
#nchar(15):一个字符占2个字节，固定长度是15，例如“hello world”,实际存储“hello world0000”
#varchar(15):一个字符占1个字节，最大长度是15，例如“hello world”,实际存储“hello world”
#nvarchar(15):一个字符占2个字节，最大长度是15，例如“hello world”,实际存储“hello world”

#建表约束
#主键：primary key,每个表中只能有一列主键列，数据唯一且不为空
#唯一：unique,数据唯一
#不为空：not null,数据不为空
#默认值：default
#自增：auto_increment
#外键约束：

# 创建一个学生信息表：学号 主键 自增 姓名 唯一 不为空，年龄 默认18 性别 枚举值
create table studentInfo(
id int primary key auto_increment,
name varchar(20) unique not null,
age int default 18,
sex enum('男','女'),
profession varchar(10)
);
# 查询表中数据：select
# 查询所有列中的数据：select * from 表名；
# 查询部分列中的数据：select 列名1，列名2，...from 表名；
# 给查询到的列名起别名：select 列名1 别名1，列名2，别名2...from 表名；
select * from studentinfo;
select name,sex,id from studentinfo;
select name 姓名,sex 性别，id from studentinfo;

# 插入数据，insert into 表明...;
# 插入所有列数据（值的顺序和表中列的顺序一致）：insert into 表明 values(值1，值2，...);
# 插入部分列的数据（值的顺序和前面列的顺序一致）；insert into 表明（列名1，列名2...）values(值1，值2，...);
insert into studentinfo values(1,'刘金朋','18','男','软件'); 
insert into studentinfo(sex,name)values('男','赵宏波');
insert into studentinfo (sex,name)values('男','赵波');

# 修改数据：update 表明 set 列名=新的值 where条件（筛选行）；
update studentinfo set id=3 where name='赵波';
# 删除数据；delete from 表名 where 条件（筛选行）；
delete from studentinfo where id = 4;

#修改表：alter table 表名....;
#1.增加列:alter table 表名 add column 列名 数据类型 建表约束
alter table studentinfo add column school int;

#2.修改列的属性：alter table 表名 modify 列名 数据类型建表约束alter
alter table studentinfo modify school varchar(20);

#3.删除列：alter table 表名 drop 列名;
alter table studentinfo drop school ;

#删除表：drop table 表名;
drop table studentinfo;

#条件：where 条件 
#相等，不相等  : 列=值; 列!=值;（只有MySQL支持）列<>值;
#大于，小于，大于等于，小于等于  : 列>值; 列<值; 列>=值; 列<=值;
#或者：条件1 or 条件2;
#并且：条件1 and 条件2;
#在两者之前：between 值1 and 值2;[值1，值2]
#在范围内：in（范围）;
#不在范围内：not in (范围）;

#查询女同学和19岁以上的同学 
select * from studentinfo where sex = '女' or age >=19;

#查询18岁以上20岁以下的同学
select * from studentinfo where age between 18 and 20;

#查询学号在1，3，5，9范围内的同学 
select * from studentinfo where id in (1,3,5,9);

#模糊查询 :列名 like 模糊表达式 :
#模糊表达式： 
# %:可以匹配任意0-n个字符
# _可以匹配任意1个字符

#查询班级中所有姓赵的同学
select * from studentinfo where name like '%赵';

#查询班级中所有三个字姓赵的同学
select * from studentinfo where name like '赵_';

#查询名字中带朋字的同学
select * from studentinfo where name like '%朋%';

#查询名字两个字以上的中带朋字的同学
select * from studentinfo where name like '%_朋';

#分页查询：limit a,b; (a:起始行号，从0开始计数; b:查询几行数据）

#查询从第三行开始，查五行数据
select * from studentinfo limit 3, 5;

#每页显示两行，查询第三页的数据 (page-1)*count
select * from studentinfo limit 4, 2;

create table Student(S varchar(10),Sname nvarchar(10),Sage datetime,Ssex nvarchar(10));
insert into Student values('01' , N'赵雷' , '1990-01-01' , N'男');
insert into Student values('02' , N'钱电' , '1990-12-21' , N'男');
insert into Student values('03' , N'孙风' , '1990-05-20' , N'男');
insert into Student values('04' , N'李云' , '1990-08-06' , N'男');
insert into Student values('05' , N'周梅' , '1991-12-01' , N'女');
insert into Student values('06' , N'吴兰' , '1992-03-01' , N'女');
insert into Student values('07' , N'郑竹' , '1989-07-01' , N'女');
insert into Student values('08' , N'王菊' , '1990-01-20' , N'女');

create table Course(C varchar(10),Cname nvarchar(10),T varchar(10));
insert into Course values('01' , N'语文' , '02');
insert into Course values('02' , N'数学' , '01');
insert into Course values('03' , N'英语' , '03');

create table Teacher(T varchar(10),Tname nvarchar(10));
insert into Teacher values('01' , N'张三');
insert into Teacher values('02' , N'李四');
insert into Teacher values('03' , N'王五');

create table SC(S varchar(10),C varchar(10),score decimal(18,1));
insert into SC values('01' , '01' , 80);
insert into SC values('01' , '02' , 90);
insert into SC values('01' , '03' , 99);
insert into SC values('02' , '01' , 70);
insert into SC values('02' , '02' , 60);
insert into SC values('02' , '03' , 80);
insert into SC values('03' , '01' , 80);
insert into SC values('03' , '02' , 80);
insert into SC values('03' , '03' , 80);
insert into SC values('04' , '01' , 50);
insert into SC values('04' , '02' , 30);
insert into SC values('04' , '03' , 20);
insert into SC values('05' , '01' , 76);
insert into SC values('05' , '02' , 87);
insert into SC values('06' , '01' , 31);
insert into SC values('06' , '03' , 34);
insert into SC values('07' , '02' , 89);
insert into SC values('07' , '03' , 98);
insert into SC values('09' , '03' , 98);

select * from studentinfo;

#聚合函数
#查行数：count（列名） 
select count(*) from studentinfo;
select count(profession) from studentinfo;
select * from studentinfo;

select * from student;
select * from sc;
select * from course;
select * from teacher;

#求和：sum(列名）
select sum(score) from sc;

#查询01同学的总成绩 
select sum(score) from sc where S = '01';

#求最大值：max(列名)
#查询03课程的最高分
select max(score) from sc where C = '03';

#求最小值：min(列名)
select min(score) from sc where C = '03';

#求平均值：avg(列名)
#计算05号同学的平均分
select avg(score) from sc where S = '05';

#分组：group by 列名;
#查询每个同学的平均分 
select S,avg(score) from sc group by S;

#查询平均分超过60的同学
#1.计算每个同学的平均分
select S,avg(score) from sc group by S;
#2.平均分超过60
select S,avg(score) from sc group by S having avg(score) >= 60;

#什么时候用where和having
#当作为条件的列是表中原来就有的，用where加
#当作为条件的列不是表中原来就有的，用having加



# 1、查询每门课程被选修的学生数
select count(S) from sc group by c;

# 2、检索至少选修两门课程的学生学号
#2.1查询每个学生选修课的个数
select count(C) from sc group by S;
#2.2课程的个数大于等于2
select S from sc group by S having count(C) >= 2;

# 3、求这些学号对应的个人信息
select * from student where S in(select S from sc group by S having count(C) >= 2);

# 4、查询选修了全部课程的学生信息
#4.1每个同学选修课程的个数
select count(C) from sc group by S;
#4.2查询全部课程的个数
select count(*) from course; 
#4.3每个同学选修课程的个数=全部课程的个数
select S from sc group by S having count(C)=(select count(*) from course);
#4.4根据学生的编号查询信息
select * from student where S in(select S from sc group by S having count(C)=(select count(*) from course));

# 5、查询没有学全所有课程的同学的信息
select * from student where S not in(select S from sc group by S having count(C)=(select count(*) from course));

# 6、查询学过"张三"老师授课的同学的信息
select T from teacher where Tname = '张三';
select C from course where T = (select T from teacher where Tname = '张三');
select S from course where C in(select C from course where T = (select T from teacher where Tname = '张三'));
select * from student where S in(select S from course where C in(select C from course where T = (select T from teacher where Tname = '张三')));

# 7、查询没学过"张三"老师授课的同学的信息
select * from student where S not in(select S from course where C in(select C from course where T = (select T from teacher where Tname = '张三')));

# 8、查询每个同学01课程的成绩，包括个人信息
#8.1查询每个同学01课程的成绩
select S,score from sc where C = '01';
#8.2个人信息
select * from student;
select*,(select score from sc where C ='01' and student.S = sc.S) 01score from student;

# 9、查询01课程分数 > 02课程分数 的个人信息
select* from student having (select score from sc where C ='01' and student.S = sc.S) > (select score from sc where C ='02' and student.S = sc.S);

# 10、查询同时存在"01"课程和"02"课程的学生信息
select * from student having(select score from sc where C ='01' and student.S = sc.S) is not null and (select score from sc where C ='02' and student.S = sc.S) is not null;

#多表联查
#1.内联：selcet * from 表1 inner join 表2 on 连接条件 inner join 表3 on 连接条件;
#2.左联：selcet * from 表1 left join 表2 on 连接条件;
#3.右联：selcet * from 表1 right join 表2 on 连接条件;
#4.笛卡尔积：selcet * from 表1,表2 where 连接条件;

select * from student inner join sc on sc.S = student.S;
select * from student left join sc on sc.S = student.S;
select * from student right join sc on sc.S = student.S;
select * from sc right join student on sc.S = student.S;#与左联一样
select * from student,sc where sc.S =student.S;

#区别：
#内联：取两个表的交集，不会出现空数据 
#左联：以左边的表为基准，从右边的表中匹配行
#右联：以右边的表为基准，从左边的表中匹配行
#笛卡尔积：查询结果和内联一样，但查询效率低，采用的是配列组合的方式

# 练习
# 1、查询成绩高于60分的学生信息
select distinct student.s,student.sname from student right join sc on student.s = sc.s where sc.score>60; 

# 2、查询每个学生的总成绩以及学生信息
select student.*,sum(sc.score) 
from student left join sc on student.s = sc.s 
group by student.s,student.Sname,student.Sage,student.Ssex;  

# 3、查询总成绩 > 200的学生信息
select student.*,sum(sc.score) 
from student left join sc on student.s = sc.s 
group by student.s,student.Sname,student.Sage,student.Ssex 
having sum(sc.score) > 200;

# 4、查询总成绩最低的学生信息

# 5、查询总成绩最低的那个人的学号

# 6、查询学过"张三"老师授课的同学的信息
select student.*
from Student inner join SC 
on Student.S = SC.S 
inner join Course 
on SC.C = Course.C inner join Teacher on Course.T = Teacher.T 
where Teacher.Tname = "张三";

# 作业：全部使用多表查询

#1、查询平均成绩大于等于60分的同学的学生编号和学生姓名和平均成绩。
select Student.S,Student.Sname,avg(SC.score) 
from Student inner join SC on Student.S = SC.S 
group by Student.S,Student.Sname 
having avg(SC.score) >= 60;
#2、查询每门课程被选修的学生数-- 带课程名字 。
select Course.Cname,count(S) from sc inner join Course on SC.C = Course.C group by Course.C,Course.Cname;
#3、查询每门课程被选修的学生数，排序按照选修的学生人数降序排序 , 如果人数相等按照课程号升序排列。
select Course.Cname,count(S) 
from sc inner join Course on SC.C = Course.C 
group by Course.C,Course.Cname
order by count(S) desc,
Course.Cname asc;
#4、查询同时存在"01"课程和"02"课程的学生的学生信息。
select student.*
from student inner join sc sc1 on student.S = sc1.S 
and sc1.C = '01'inner join sc sc2 on student.S = sc2.S 
and sc2.C = '02';

#视图：view
#简化复杂的select语句而溢出的概念。视图是一个表或者多个表导出的虚拟表，，不是真实存在的，不需要满足范式的要求 

#创建语法：create view 视图名 as(select)语句
#使用视图：select * from 视图名
#删除：drop view 视图名

create view myview as(select student.*,C,score from student inner join sc on sc.S = student.S);
select * from myview;
drop view myview;

#函数：function

#创建函数语法:
#delimiter //        #设置//为sql语句新的结束标志
#create function 函数名(变量名 数据类型,变量名 数据类型,...)
#returns 返回值类型
#begin
#函数语句;
#函数语句;
#end //
#delimiter ;         #重新设置;为sql语句的结束标志

#使用函数:select 函数名(参数列表);
#删除函数:drop function 函数名;     

#例子：实现一个加法函数
 delimiter // 
 create function myadd(a int, b int)
 returns int
 begin
	declare c int default 0;
	set c = a + b;
    return c;
 end //
delimiter ; 

select myadd(3,7);

#变量
#局部变量：函数内部定义的变量，用declare定义 
#会话变量：声明周期就是一次会话，会话变量以@开头
set @a = 10;
select @a;
#系统变量(全局变量)：不允许自己定义，只能查看或改变变量的值
#查看所有的系统变量
show global variables;
#查看某个变量值 
select @@binlog_error_action;

#判断
#if判断语法：
#if(表达式1) then 执行语句;执行语句;执行语句;
#elseif(表达式2) then 执行语句;执行语句;执行语句;
#else 执行语句;执行语句;执行语句;
#end if;

#定义一个函数，判断输入数据是正数、负数还是0
delimiter //
create function myfun(n int)
returns varchar(5)
begin
	declare res varchar(5) default '';
    if(n>0) then set res='正数';
	elseif(n=0) then set res='零';
	else set res = '负数';
    end if;
	return res;
end //
 delimiter ;
select myfun(-10);

#case判断
#语法1：
#case 变量 when 值1 then 执行语句；执行语句；
#          when 值2 then 执行语句；执行语句；
#          when 值3 then 执行语句；执行语句；
#语法2：
#case when 表达式1 then 执行语句；执行语句；
#     when 表达式2 then 执行语句；执行语句；
#     when 表达式3 then 执行语句；执行语句；

delimiter //
create function mycase(a int)
returns varchar(5)
begin
	declare res varchar(5) default '';
    case when a>0 then set res='正数';
         when a=0 then set res='零';
         when a<0 then set res='负数';
    end case;
	return res;
end //
delimiter ;
select mycase(10);

# 循环
# while 循环条件
# do
# 语句;
# end while;

# 作业:
# 1、青蛙爬井 ，白天向上爬5m，夜晚向下滑4m，问多少天爬出井。
# 使用函数实现 ，传入参数是井的高度（high int），返回值是需要的天数（day int）。
delimiter //
create function qwpj(high int)
returns int
DETERMINISTIC
begin
	declare day int default 0;
    declare m int default 0;
    while 1 = 1	do
		set m = m + 5;
        set day = day + 1;
        if(m >= high) then return day;
        end if;
        set m = m - 4;
	end while;	
end//
delimiter ;

select qwpj(10);

# 存储过程:procedure
# 在大型数据库系统中,一组为了完成特定功能的sql语句集合.
# 存储在数据库中,一次编译永久有效

# 优点:
# 1.减少网络流量
# 2.增强代码的重用性和共享性
# 3.加快系统的运行速度
# 4.更灵活

# 创建存储过程语法:
# delimiter //
# create procedure 存储过程名(变量1 类型,.....)
# begin
#	执行语句;
# end
# delimiter ;
# 注意:存储过程没有返回值,函数参数可以是in|out|inout类型,默认是in类型,可以通过参数返回参数数据

# 执行存储过程:call 存储过程名(参数列表);
# 删除存储过程:drop procedure 存储过程名;

# 例子:实现分页查询的存储过程.固定查询student表.
# 输入参数:当前是第几页 nPage int,每页显示多少行 nCount int .

delimiter //
create procedure mylimit(nPage int,nCount int)
begin
	declare nOffset int default 0;
    declare totalRows int default 0;  -- 总行数
    declare maxPage int default 1;    -- 最大页数（默认至少1页）
	#查询总行数
    select count(student.S) into totalRows from student;
    #计算最大页数：总行数除以每页显示多少行，不能整除的时候向上取整
     if totalRows > 0 then
        set maxPage = ceil(totalRows / nCount);  -- ceil() 向上取整函数
    end if;
    #判断参数合法性，如果当前页数小于1，显示第一页内容；
	#如果当前页数大于最大页数，就显示最后一页内容
    if nPage < 1 then
        set nPage = 1;  -- 页数小于1，显示第1页
    elseif nPage > maxPage then
        set nPage = maxPage;  -- 页数大于最大页，显示最后1页
    end if;
   
    #计算起始行数
    set nOffset = (nPage - 1) * nCount;
    
    select * from student limit nOffset,nCount;
end//
delimiter ;

drop procedure mylimit;

call mylimit(2,5);

# 存储过程和函数的区别
# 1.函数不能有返回值,存储过程没有返回值,但是可以通过out|inout参数返回数据;
# 2.函数中不能包含sql语句,存储过程中可以有sql语句

# 触发器:trigger
# 是一种特殊的触发器,当指定事件(增加,修改,删除)发生的时候,系统自动调用.

# 创建触发器的语法
# delimiter //
# create trigger 触发器名字after/before 操作名
# on 表名
# for each row
# begin
# 执行语句;
# end//
# dilimiter ;

# 删除触发器: drop trigger 触发器名字;

# 例子:实现触发器,一个删除student表的时候,自动删除sc表的相关行
delimiter //
create trigger droptrigger after delete
on student
for each row
begin
	#自动删除sc表中相关行
	delete from sc where s = old.s;
    #old表：删除之前的数据，更新之前的数据
    #new表：更新之后的数据，新增的数据
end//
delimiter ;
delete from student where s = '01';

select * from student inner join sc on sc.S=student.S;



# 例子：实现触发器，当student表中新增加一个同学，给这个同学自动选择01和02课程，分数是null
delimiter //
create trigger inserttrigger 
after insert
on student
for each row
begin
	insert into sc (S, C, score) values (NEW.S, '01', NULL);
    insert into sc (S, C, score) values (NEW.S, '02', NULL);
end //
delimiter ;
# student表中新增加一个同学
insert into student (S, Sname, Ssex) values ('15', '朱禹彤', '女');

select * from student;
select * from sc;

# 例子：实现触发器，当修改新增的同学的学号时候，自动修改sc表中这个同学的学号
delimiter //
create trigger myupdate
after update
on student
for each row
begin
	# 自动修改sc表中这个同学的学号
    update sc set S = new.S where S = old.S;
end //
delimiter ;
# 修改新增的同学的学号
update student set S = '20' where S = '15';

# 事务: transaction
create table bank(
	name varchar(10),
	money double not null,
    check(money>=0)	# check()在mysql中是无效的
);

insert into bank value ('刘金朋','1000000');
insert into bank value ('韩东轩','0');

select * from bank;
# 借钱,借500000
update bank set money = money - 500000 where name = '刘金朋';
update bank set money = money + 500000 where name = '韩东轩';

# 事务特性:
# 1.原子性: 事务是最小的工作单元,不可再分,要么都执行，要么都不执行.
# 2.一致性: 数据库的完整性约束不能被破坏
# 3.隔离性: 并行执行的事务是隔离的,相互之间不影响
# 4.持久性: 事务提交以后,数据改变永久保存

# 开启事务: start transaction
# 执行语句;
# 执行语句;
# 执行语句;
# 提交:commit  #sql语句的结果想要保存下来
# 回滚:rollback; #sql语句的结果不想要 数据恢复到开启事务之前的状态
 
start transaction;
# 借钱,借500000
update bank set money = money + 500000 where name = '韩东轩';
update bank set money = money - 500000 where name = '刘金朋';

select * from bank;

rollback;

commit;

CREATE DATABASE IF NOT EXISTS campus_lost_found_db CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE campus_lost_found_db;


-- 物品类别表
CREATE TABLE IF NOT EXISTS t_item_category (
    category_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    category_name VARCHAR(50) UNIQUE NOT NULL,
    category_desc VARCHAR(200),
    create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

-- 校园地点表
CREATE TABLE IF NOT EXISTS t_campus_location (
    location_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    location_name VARCHAR(100) UNIQUE NOT NULL,
    location_type VARCHAR(50) NOT NULL,
    detailed_addr VARCHAR(200),
    create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

-- 用户表
CREATE TABLE IF NOT EXISTS t_user (
    user_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(100) NOT NULL,
    real_name VARCHAR(50) NOT NULL,
    role_type VARCHAR(20) NOT NULL CHECK (role_type IN ('学生', '教职工', '管理员')),
    student_id VARCHAR(20) UNIQUE,
    staff_id VARCHAR(20) UNIQUE,
    phone VARCHAR(20) NOT NULL,
    college_dept VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    register_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    account_status VARCHAR(20) NOT NULL DEFAULT '正常' CHECK (account_status IN ('正常', '禁用'))
);

-- 失物信息表
CREATE TABLE IF NOT EXISTS t_lost_item (
    lost_item_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    item_name VARCHAR(100) NOT NULL,
    category_id INT NOT NULL,
    feature_desc TEXT NOT NULL,
    pick_time DATETIME NOT NULL,
    pick_location_id INT NOT NULL,
    store_location VARCHAR(100) NOT NULL,
    item_photo_url VARCHAR(255),
    picker_id INT NOT NULL,
    audit_status VARCHAR(20) NOT NULL DEFAULT '待审核' CHECK (audit_status IN ('待审核', '已通过', '未通过')),
    audit_opinion VARCHAR(200),
    publish_time DATETIME,
    update_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (category_id) REFERENCES t_item_category(category_id),
    FOREIGN KEY (pick_location_id) REFERENCES t_campus_location(location_id),
    FOREIGN KEY (picker_id) REFERENCES t_user(user_id)
);

-- 寻物信息表
CREATE TABLE IF NOT EXISTS t_found_item (
    found_item_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    item_name VARCHAR(100) NOT NULL,
    category_id INT NOT NULL,
    feature_desc TEXT NOT NULL,
    lose_time DATETIME NOT NULL,
    lose_location_id INT NOT NULL,
    item_photo_url VARCHAR(255),
    owner_id INT NOT NULL,
    reward_desc VARCHAR(200),
    publish_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    update_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    status VARCHAR(20) NOT NULL DEFAULT '未找到' CHECK (status IN ('未找到', '已找到', '已撤销')),
    FOREIGN KEY (category_id) REFERENCES t_item_category(category_id),
    FOREIGN KEY (lose_location_id) REFERENCES t_campus_location(location_id),
    FOREIGN KEY (owner_id) REFERENCES t_user(user_id)
);

-- 认领申请表
CREATE TABLE IF NOT EXISTS t_claim_application (
    claim_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    lost_item_id INT NOT NULL,
    found_item_id INT NOT NULL,
    applicant_id INT NOT NULL,
    claim_desc TEXT NOT NULL,
    apply_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    verify_status VARCHAR(20) NOT NULL DEFAULT '待核实' CHECK (verify_status IN ('待核实', '核实通过', '核实驳回')),
    verify_opinion VARCHAR(200),
    confirm_time DATETIME,
    admin_id INT,
    FOREIGN KEY (lost_item_id) REFERENCES t_lost_item(lost_item_id),
    FOREIGN KEY (found_item_id) REFERENCES t_found_item(found_item_id),
    FOREIGN KEY (applicant_id) REFERENCES t_user(user_id),
    FOREIGN KEY (admin_id) REFERENCES t_user(user_id)
);

-- 系统日志表
CREATE TABLE IF NOT EXISTS t_system_log (
    log_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    operator_id INT NOT NULL,
    operation_type VARCHAR(50) NOT NULL,
    operation_desc VARCHAR(255) NOT NULL,
    operation_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    ip_address VARCHAR(50) NOT NULL,
    FOREIGN KEY (operator_id) REFERENCES t_user(user_id)
);

-- 信息匹配表
CREATE TABLE IF NOT EXISTS t_info_matching (
    match_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    lost_item_id INT NOT NULL,
    found_item_id INT NOT NULL,
    match_degree INT NOT NULL CHECK (match_degree BETWEEN 0 AND 100),
    match_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    is_notified TINYINT NOT NULL DEFAULT 0 CHECK (is_notified IN (0, 1)),
    FOREIGN KEY (lost_item_id) REFERENCES t_lost_item(lost_item_id),
    FOREIGN KEY (found_item_id) REFERENCES t_found_item(found_item_id)
);

-- 插入物品类别数据
INSERT INTO t_item_category (category_name, category_desc) VALUES
('电子设备', '手机、电脑、平板、耳机等电子产品'),
('证件', '身份证、学生证、教职工证、银行卡等'),
('文具', '笔、笔记本、文件夹、U盘等学习用品'),
('衣物', '外套、围巾、帽子、鞋子等穿戴物品'),
('书籍', '教材、课外书、杂志等'),
('背包', '书包、双肩包、手提包等'),
('饰品', '手表、项链、手链、眼镜等'),
('其他', '无法归类的其他物品');

-- 插入校园地点数据
INSERT INTO t_campus_location (location_name, location_type, detailed_addr) VALUES
('图书馆1楼服务台', '图书馆', '校园西区图书馆1楼大厅'),
('教学楼A栋302教室', '教学楼', '校园东区教学楼A栋3楼'),
('第一食堂2楼', '食堂', '校园北区第一食堂2楼就餐区'),
('操场主席台', '运动场地', '校园南区标准操场主席台旁'),
('学生宿舍3栋楼下', '宿舍', '校园东区学生宿舍3栋出入口'),
('行政楼205办公室', '行政楼', '校园中区行政楼2楼205室'),
('实验室B栋101', '实验室', '校园西区实验室B栋1楼'),
('校园超市收银台', '商业设施', '校园北区校园超市内'),
('篮球场2号场地', '运动场地', '校园南区篮球场2号场'),
('快递驿站门口', '服务设施', '校园东区快递驿站出入口');

-- 插入用户数据（密码统一加密为123456的MD5值：e10adc3949ba59abbe56e057f20f883e）
INSERT INTO t_user (username, password, real_name, role_type, student_id, staff_id, phone, college_dept, email) VALUES
('student01', 'e10adc3949ba59abbe56e057f20f883e', '张三', '学生', '2404060501', NULL, '13800138001', '计算机学院', 'zhangsan@xxx.com'),
('student02', 'e10adc3949ba59abbe56e057f20f883e', '李四', '学生', '2404060502', NULL, '13800138002', '软件工程学院', 'lisi@xxx.com'),
('staff01', 'e10adc3949ba59abbe56e057f20f883e', '王五', '教职工', NULL, 'G2024001', '13800138003', '图书馆', 'wangwu@xxx.com'),
('staff02', 'e10adc3949ba59abbe56e057f20f883e', '赵六', '教职工', NULL, 'G2024002', '13800138004', '学生处', 'zhaoliu@xxx.com'),
('admin01', 'e10adc3949ba59abbe56e057f20f883e', '孙七', '管理员', NULL, 'A2024001', '13800138005', '信息中心', 'sunqi@xxx.com'),
('student03', 'e10adc3949ba59abbe56e057f20f883e', '周八', '学生', '2404060503', NULL, '13800138006', '电子信息学院', 'zhouba@xxx.com'),
('student04', 'e10adc3949ba59abbe56e057f20f883e', '吴九', '学生', '2404060504', NULL, '13800138007', '自动化学院', 'wujia@xxx.com'),
('staff03', 'e10adc3949ba59abbe56e057f20f883e', '郑十', '教职工', NULL, 'G2024003', '13800138008', '食堂管理处', 'zhengshi@xxx.com'),
('student05', 'e10adc3949ba59abbe56e057f20f883e', '钱十一', '学生', '2404060505', NULL, '13800138009', '文学院', 'qianshiyi@xxx.com'),
('student06', 'e10adc3949ba59abbe56e057f20f883e', '冯十二', '学生', '2404060506', NULL, '13800138010', '外国语学院', 'fengshier@xxx.com');

-- 插入失物信息数据
INSERT INTO t_lost_item (item_name, category_id, feature_desc, pick_time, pick_location_id, store_location, item_photo_url, picker_id, audit_status, publish_time) VALUES
('华为Mate40手机', 1, '黑色外壳，背面有轻微划痕，无SIM卡', '2025-11-01 10:30:00', 1, '图书馆服务台', 'https://photo1.jpg', 3, '已通过', '2025-11-01 11:00:00'),
('学生证', 2, '学号2404060510，姓名陈十三，软件工程学院', '2025-11-02 14:15:00', 2, '教学楼A栋值班室', 'https://photo2.jpg', 4, '已通过', '2025-11-02 15:00:00'),
('小米Air2耳机', 1, '白色，充电盒有小米logo，左耳耳机轻微掉漆', '2025-11-03 09:45:00', 3, '第一食堂服务台', 'https://photo3.jpg', 8, '已通过', '2025-11-03 10:30:00'),
('《数据库系统概论》教材', 5, '第5版，高等教育出版社，封面有笔记', '2025-11-04 16:20:00', 1, '图书馆服务台', 'https://photo4.jpg', 3, '已通过', '2025-11-04 17:00:00'),
('黑色双肩包', 6, '品牌耐克，内侧有姓名标签“李十四”', '2025-11-05 11:25:00', 5, '宿舍3栋值班室', 'https://photo5.jpg', 6, '已通过', '2025-11-05 12:00:00'),
('身份证', 2, '姓名王五，身份证号1101011999XXXX1234', '2025-11-06 13:50:00', 4, '操场管理处', 'https://photo6.jpg', 7, '已通过', '2025-11-06 14:30:00'),
('苹果iPad Pro', 1, '11英寸，深空灰色，带Apple Pencil', '2025-11-07 15:30:00', 7, '实验室B栋服务台', 'https://photo7.jpg', 9, '已通过', '2025-11-07 16:00:00'),
('蓝色围巾', 4, '针织材质，长度约1.5米，边缘有流苏', '2025-11-08 10:10:00', 8, '校园超市服务台', 'https://photo8.jpg', 8, '已通过', '2025-11-08 10:40:00'),
('U盘', 3, '红色，容量64G，上面刻有“XX大学”', '2025-11-09 14:40:00', 2, '教学楼A栋值班室', 'https://photo9.jpg', 4, '已通过', '2025-11-09 15:10:00'),
('近视眼镜', 7, '黑色镜框，镜片有防蓝光涂层', '2025-11-10 09:20:00', 6, '行政楼205办公室', 'https://photo10.jpg', 5, '已通过', '2025-11-10 10:00:00');

-- 插入寻物信息数据
INSERT INTO t_found_item (item_name, category_id, feature_desc, lose_time, lose_location_id, item_photo_url, owner_id, reward_desc, status) VALUES
('苹果iPhone15', 1, '粉色外壳，带透明手机壳，手机壳上有卡通图案', '2025-11-01 08:30:00', 3, 'https://photo11.jpg', 1, '酬谢200元', '未找到'),
('学生证', 2, '学号2404060512，姓名赵十五，计算机学院', '2025-11-02 11:15:00', 1, 'https://photo12.jpg', 2, '无酬谢，麻烦联系', '未找到'),
('联想拯救者笔记本', 1, '黑色，型号R9000P，背面有贴纸', '2025-11-03 16:45:00', 7, 'https://photo13.jpg', 3, '酬谢500元', '未找到'),
('《Java编程思想》', 5, '第4版，机械工业出版社，内页有大量批注', '2025-11-04 10:20:00', 2, 'https://photo14.jpg', 4, '无酬谢', '未找到'),
('白色运动鞋', 4, '品牌安踏，尺码42，鞋舌有安踏logo', '2025-11-05 15:30:00', 4, 'https://photo15.jpg', 5, '酬谢100元', '未找到'),
('银行卡', 2, '中国工商银行，卡号尾号6789，姓名孙十六', '2025-11-06 09:10:00', 8, 'https://photo16.jpg', 6, '麻烦归还，必有重谢', '未找到'),
('黑色钢笔', 3, '品牌派克，笔帽有金色装饰', '2025-11-07 14:20:00', 1, 'https://photo17.jpg', 7, '无酬谢', '未找到'),
('双肩包', 6, '灰色，品牌阿迪达斯，侧袋有水瓶', '2025-11-08 11:50:00', 5, 'https://photo18.jpg', 8, '酬谢300元', '未找到'),
('手表', 7, '卡西欧电子表，黑色表盘，防水', '2025-11-09 13:30:00', 9, 'https://photo19.jpg', 9, '无酬谢', '未找到'),
('身份证', 2, '姓名周十七，身份证号3101012000XXXX5678', '2025-11-10 16:10:00', 10, 'https://photo20.jpg', 10, '酬谢100元', '未找到');

-- 插入认领申请数据
INSERT INTO t_claim_application (lost_item_id, found_item_id, applicant_id, claim_desc, verify_status, admin_id) VALUES
(1, 1, 1, '手机是我的，粉色外壳，透明手机壳上有卡通图案，丢失时间和地点一致', '待核实', 5),
(2, 2, 2, '学生证学号2404060512，姓名赵十五，与失物信息中学号2404060510不符，申请核实', '核实驳回', 5),
(3, 3, 3, '耳机是小米Air2，白色充电盒，左耳掉漆，我丢失的耳机特征完全一致', '核实通过', 5),
(4, 4, 4, '《数据库系统概论》是我丢失的，第5版，封面有笔记，丢失地点在图书馆', '待核实', 5),
(5, 5, 5, '黑色耐克双肩包，内侧有“李十四”标签，我就是李十四，丢失在宿舍楼下', '核实通过', 5),
(6, 6, 6, '身份证姓名王五，我就是王五，身份证号尾号1234，丢失在操场', '待核实', 5),
(7, 7, 7, 'iPad Pro 11英寸，深空灰色，带Apple Pencil，我丢失的设备完全一致', '核实驳回', 5),
(8, 8, 8, '蓝色针织围巾，长度1.5米，边缘有流苏，丢失在校园超市', '待核实', 5),
(9, 9, 9, '红色64G U盘，刻有“XX大学”，我丢失的U盘特征一致', '核实通过', 5),
(10, 10, 10, '黑色镜框近视眼镜，防蓝光镜片，丢失在行政楼', '待核实', 5);

-- 插入系统日志数据
INSERT INTO t_system_log (operator_id, operation_type, operation_desc, ip_address) VALUES
(1, '登录', '学生张三登录系统', '192.168.1.101'),
(3, '录入失物', '教职工王五录入华为Mate40手机失物信息', '192.168.1.102'),
(5, '审核失物', '管理员孙七审核通过华为Mate40手机失物信息', '192.168.1.103'),
(2, '发布寻物', '学生李四发布学生证寻物信息', '192.168.1.104'),
(4, '提交认领', '教职工赵六提交小米Air2耳机认领申请', '192.168.1.105'),
(5, '审核认领', '管理员孙七核实通过小米Air2耳机认领申请', '192.168.1.106'),
(6, '修改信息', '学生周八修改个人联系方式', '192.168.1.107'),
(7, '查询失物', '学生吴九查询电子设备类失物信息', '192.168.1.108'),
(8, '录入失物', '教职工郑十录入蓝色围巾失物信息', '192.168.1.109'),
(9, '撤销寻物', '学生钱十一撤销手表寻物信息', '192.168.1.110');

-- 插入信息匹配数据
INSERT INTO t_info_matching (lost_item_id, found_item_id, match_degree, is_notified) VALUES
(1, 1, 95, 1),
(2, 2, 60, 1),
(3, 3, 90, 1),
(4, 4, 85, 0),
(5, 5, 92, 1),
(6, 6, 88, 0),
(7, 7, 75, 1),
(8, 8, 80, 0),
(9, 9, 93, 1),
(10, 10, 87, 0);

-- 查询所有已通过审核的失物信息
SELECT li.lost_item_id, li.item_name, c.category_name, li.pick_time, l.location_name, u.real_name AS picker_name
FROM t_lost_item li
JOIN t_item_category c ON li.category_id = c.category_id
JOIN t_campus_location l ON li.pick_location_id = l.location_id
JOIN t_user u ON li.picker_id = u.user_id
WHERE li.audit_status = '已通过';
-- 查询状态为 “未找到” 的寻物信息（按发布时间降序）
SELECT fi.found_item_id, fi.item_name, c.category_name, fi.lose_time, l.location_name, u.real_name AS owner_name
FROM t_found_item fi
JOIN t_item_category c ON fi.category_id = c.category_id
JOIN t_campus_location l ON fi.lose_location_id = l.location_id
JOIN t_user u ON fi.owner_id = u.user_id
WHERE fi.status = '未找到'
ORDER BY fi.publish_time DESC;

-- 查询 “电子设备” 类失物的认领情况
SELECT li.item_name, u1.real_name AS picker_name, fi.item_name AS found_item_name, u2.real_name AS applicant_name, ca.verify_status
FROM t_lost_item li
JOIN t_item_category c ON li.category_id = c.category_id
JOIN t_user u1 ON li.picker_id = u1.user_id
LEFT JOIN t_claim_application ca ON li.lost_item_id = ca.lost_item_id
LEFT JOIN t_found_item fi ON ca.found_item_id = fi.found_item_id
LEFT JOIN t_user u2 ON ca.applicant_id = u2.user_id
WHERE c.category_name = '电子设备';

-- 查询 2025 年 11 月拾获的失物及对应的匹配寻物信息
SELECT li.item_name, li.pick_time, l1.location_name AS pick_location, fi.item_name AS found_item_name, fi.lose_time, l2.location_name AS lose_location, m.match_degree
FROM t_lost_item li
JOIN t_campus_location l1 ON li.pick_location_id = l1.location_id
JOIN t_info_matching m ON li.lost_item_id = m.lost_item_id
JOIN t_found_item fi ON m.found_item_id = fi.found_item_id
JOIN t_campus_location l2 ON fi.lose_location_id = l2.location_id
WHERE DATE_FORMAT(li.pick_time, '%Y-%m') = '2025-11'
ORDER BY m.match_degree DESC;

-- 按物品类别统计失物数量
SELECT c.category_name, COUNT(li.lost_item_id) AS lost_item_count
FROM t_item_category c
LEFT JOIN t_lost_item li ON c.category_id = li.category_id AND li.audit_status = '已通过'
GROUP BY c.category_id, c.category_name
ORDER BY lost_item_count DESC;

-- 按拾获地点统计失物数量（仅统计数量≥2 的地点）
SELECT l.location_name, l.location_type, COUNT(li.lost_item_id) AS lost_count
FROM t_campus_location l
JOIN t_lost_item li ON l.location_id = li.pick_location_id AND li.audit_status = '已通过'
GROUP BY l.location_id, l.location_name, l.location_type
HAVING COUNT(li.lost_item_id) >= 2
ORDER BY lost_count DESC;

-- 查询认领申请通过的失主信息
SELECT u.user_id, u.real_name, u.phone, u.college_dept
FROM t_user u
WHERE u.user_id IN (
    SELECT ca.applicant_id
    FROM t_claim_application ca
    WHERE ca.verify_status = '核实通过'
);

-- 查询匹配度≥85 分且未推送提醒的寻物信息
SELECT fi.found_item_id, fi.item_name, fi.feature_desc, u.real_name AS owner_name
FROM t_found_item fi
JOIN t_user u ON fi.owner_id = u.user_id
WHERE fi.found_item_id IN (
    SELECT m.found_item_id
    FROM t_info_matching m
    WHERE m.match_degree >= 85 AND m.is_notified = 0
);

-- 更新寻物信息状态为 “已找到”
UPDATE t_found_item
SET status = '已找到', update_time = CURRENT_TIMESTAMP
WHERE found_item_id = 3;

-- 删除审核未通过且超过 30 天的失物信息
DELETE FROM t_lost_item
WHERE audit_status = '未通过' AND DATE_ADD(update_time, INTERVAL 30 DAY) < CURRENT_DATE();

-- 视图（View）：失物信息详情视图
CREATE VIEW v_lost_item_detail AS
SELECT 
    li.lost_item_id,
    li.item_name,
    c.category_name,
    li.feature_desc,
    DATE_FORMAT(li.pick_time, '%Y-%m-%d %H:%i:%s') AS pick_time,
    l.location_name AS pick_location,
    li.store_location,
    li.item_photo_url,
    u.real_name AS picker_name,
    u.phone AS picker_phone,
    li.audit_status,
    DATE_FORMAT(li.publish_time, '%Y-%m-%d %H:%i:%s') AS publish_time
FROM t_lost_item li
JOIN t_item_category c ON li.category_id = c.category_id
JOIN t_campus_location l ON li.pick_location_id = l.location_id
JOIN t_user u ON li.picker_id = u.user_id;

-- 存储过程（Stored Procedure）：批量插入校园地点
DELIMITER //
CREATE PROCEDURE batch_insert_location(
    IN location_names VARCHAR(1000),  -- 地点名称，用逗号分隔
    IN location_types VARCHAR(1000), -- 地点类型，用逗号分隔
    IN detailed_addrs VARCHAR(2000)  -- 详细地址，用逗号分隔
)
BEGIN
    DECLARE i INT DEFAULT 1;
    DECLARE location_name VARCHAR(100);
    DECLARE location_type VARCHAR(50);
    DECLARE detailed_addr VARCHAR(200);
    DECLARE total INT;
    
    -- 计算地点总数
    SET total = LENGTH(location_names) - LENGTH(REPLACE(location_names, ',', '')) + 1;
    
    WHILE i <= total DO
        -- 提取单个地点名称
        SET location_name = SUBSTRING_INDEX(SUBSTRING_INDEX(location_names, ',', i), ',', -1);
        -- 提取单个地点类型
        SET location_type = SUBSTRING_INDEX(SUBSTRING_INDEX(location_types, ',', i), ',', -1);
        -- 提取单个详细地址
        SET detailed_addr = SUBSTRING_INDEX(SUBSTRING_INDEX(detailed_addrs, ',', i), ',', -1);
        
        -- 插入数据
        INSERT INTO t_campus_location (location_name, location_type, detailed_addr)
        VALUES (location_name, location_type, detailed_addr);
        
        SET i = i + 1;
    END WHILE;
END //
DELIMITER ;

-- 调用示例
CALL batch_insert_location(
    '网球场,羽毛球馆,第二食堂',
    '运动场地,运动场地,食堂',
    '校园南区网球场,校园南区羽毛球馆,校园北区第二食堂'
);

DELIMITER //
CREATE FUNCTION calculate_match_degree(
    lost_feature TEXT,  -- 失物特征
    found_feature TEXT  -- 寻物特征
) RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE match_score INT DEFAULT 0;
    DECLARE lost_keywords TEXT;
    DECLARE found_keywords TEXT;
    
    -- 简单匹配规则：提取关键词（此处简化为字符串相似度计算）
    SET match_score = ROUND((1 - (LENGTH(REPLACE(CONCAT(lost_feature, found_feature), lost_feature, '')) / LENGTH(found_feature))) * 100);
    
    -- 边界处理：匹配度不低于0，不高于100
    IF match_score < 0 THEN SET match_score = 0;
    ELSEIF match_score > 100 THEN SET match_score = 100;
    END IF;
    
    RETURN match_score;
END //
DELIMITER ;

-- 调用示例
SELECT calculate_match_degree('黑色外壳，背面有轻微划痕', '粉色外壳，带透明手机壳') AS match_degree;

-- 索引（Index）：失物信息查询索引
-- 为失物信息表的类别ID、拾获时间、审核状态创建联合索引
CREATE INDEX idx_lost_item_query ON t_lost_item (category_id, pick_time, audit_status);

-- 为寻物信息表的失主ID、状态创建索引
CREATE INDEX idx_found_item_owner_status ON t_found_item (owner_id, status);

-- 触发器（Trigger）：失物审核通过后自动发布时间
DELIMITER //
CREATE TRIGGER trg_lost_item_audit
BEFORE UPDATE ON t_lost_item
FOR EACH ROW
BEGIN
    -- 当审核状态从“待审核”更新为“已通过”时，自动设置发布时间
    IF OLD.audit_status = '待审核' AND NEW.audit_status = '已通过' THEN
        SET NEW.publish_time = CURRENT_TIMESTAMP;
    END IF;
END //
DELIMITER ;

-- 事务（Transaction）：认领确认流程
DELIMITER //
CREATE PROCEDURE confirm_claim(
    IN p_claim_id INT,
    IN p_admin_id INT,
    IN p_verify_opinion VARCHAR(200)
)
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        SELECT '认领确认失败，事务回滚' AS result;
    END;
    
    START TRANSACTION;
    
    -- 1. 更新认领申请状态
    UPDATE t_claim_application
    SET verify_status = '核实通过',
        verify_opinion = p_verify_opinion,
        confirm_time = CURRENT_TIMESTAMP,
        admin_id = p_admin_id
    WHERE claim_id = p_claim_id;
    
    -- 2. 获取对应的寻物ID
    SET @found_item_id = (SELECT found_item_id FROM t_claim_application WHERE claim_id = p_claim_id);
    
    -- 3. 更新寻物信息状态为“已找到”
    UPDATE t_found_item
    SET status = '已找到',
        update_time = CURRENT_TIMESTAMP
    WHERE found_item_id = @found_item_id;
    
    COMMIT;
    SELECT '认领确认成功' AS result;
END //
DELIMITER ;

-- 调用示例
CALL confirm_claim(3, 5, '核实失主提供的特征与失物完全一致，同意认领');

show 