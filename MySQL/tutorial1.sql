create database `first_data`;
show databases;
use `first_data`;

create table `employee` (
	`emp_id` int primary key auto_increment,
    `name` varchar(20) not null,
    `birthday` varchar(20),
    `gender` varchar(20),
    `salary` int
);
drop table `employee`;
describe `employee`;

insert into `employee` values(206, 'Alice', '1999/10/8', 'F', 50000);
insert into `employee`(`name`, `birthday`, `gender`, `salary`) values('Bob', '1985/9/16', 'M', 30000);
insert into `employee`(`name`, `birthday`, `gender`, `salary`) values('Herry', '2000/12/19', 'M', 35000);
insert into `employee`(`name`, `birthday`, `gender`, `salary`) values('Eve', '1997/1/229', 'F', 47000);
insert into `employee`(`name`, `birthday`, `gender`, `salary`) values('John', '2000/12/19', 'M', 68000);

select * from `employee`;
select * from `employee` order by `salary` desc limit 2;

set SQL_SAFE_UPDATES=0;

create table `branch` (
	`branch_id` int primary key auto_increment,
    `branch_name` varchar(20)
);
drop table `branch`;
insert into `branch` values(1, 'RD');
insert into `branch`(`branch_name`) values('ADM');
insert into `branch`(`branch_name`) values('IT');
insert into `branch`(`branch_name`) values('EE');
insert into `branch`(`branch_name`) values('HR');

update `branch`
set `branch_name` = 'IE'
where `branch_name` = 'IT' or `branch_name` = 'EE';

delete from `branch`
where `branch_id` > 2;

select * from `branch`;