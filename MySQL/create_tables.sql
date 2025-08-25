create database `first_data`;
show databases;
use `first_data`;
show tables;

create table `employee` (
	`emp_id` int primary key auto_increment,
    `name` varchar(20) not null,
    `birthday` varchar(20),
    `gender` varchar(20),
    `salary` int,
    `branch_id` int,
    `buddy_id` int
);
create table `branch` (
	`branch_id` int primary key auto_increment,
    `branch_name` varchar(20),
    `manager_id` int
);
alter table `employee`
add foreign key(`buddy_id`)
references `employee`(`emp_id`)
on delete set null;

alter table `employee`
add foreign key(`branch_id`)
references `branch`(`branch_id`)
on delete set null;

alter table `branch`
add foreign key(`manager_id`)
references `employee`(`emp_id`)
on delete set null;

create table `client` (
	`client_id` int primary key,
    `client_name` varchar(20),
    `phone` varchar(20)
);
create table `works_with` (
	`emp_id` int,
    `client_id` int,
    `total_sales` int,
    primary key(`emp_id`, `client_id`),
    foreign key(`emp_id`) references `employee`(`emp_id`) on delete cascade,
    foreign key(`client_id`) references `client`(`client_id`) on delete cascade
);
