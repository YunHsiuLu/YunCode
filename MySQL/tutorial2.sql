set SQL_SAFE_UPDATES=0;
show databases;
use `first_data`;
show tables;
select * from `employee`;
select * from `branch`;
select * from `client`;
select * from `works_with`;

drop database `first_data`;

alter table `branch` add `manager_id` int;

alter table `branch`
add foreign key(`manager_id`)
references `employee`(`emp_id`)
on delete set null;

update `branch`
set `manager_id` = 208
where `branch_id` = 3;


create table `client` (
	`client_id` int primary key,
    `client_name` varchar(20),
    `phone` varchar(20)
);

insert into `client` values(401, 'Apple', '3412');
insert into `client` values(402, 'Banana', '55688');
insert into `client` values(403, 'Candy', '4022');
insert into `client` values(404, 'Dino', '34157');
insert into `client` values(405, 'ETE', '8864');

create table `works_with` (
	`emp_id` int,
    `client_id` int,
    `total_sales` int,
    primary key(`emp_id`, `client_id`),
    foreign key(`emp_id`) references `employee`(`emp_id`) on delete cascade,
    foreign key(`client_id`) references `client`(`client_id`) on delete cascade
);


insert into `works_with`(`total_sales`) values(70000);
insert into `works_with` values(207, 401, 24000);
insert into `works_with` values(208, 400, 10000);
insert into `works_with` values(208, 403, 24000);
insert into `works_with` values(210, 404, 88000);
