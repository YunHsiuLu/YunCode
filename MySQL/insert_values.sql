insert into `branch` values(1, 'RD', null);
insert into `branch`(`branch_name`, `manager_id`) values('ADM', null);
insert into `branch`(`branch_name`, `manager_id`) values('IT', null);


insert into `employee` values(206, 'Alice', '1999/10/8', 'F', 50000, 1, null);
insert into `employee`(`name`, `birthday`, `gender`, `salary`, `branch_id`, `buddy_id`) values('Bob', '1985/9/16', 'M', 30000, 2, null);
insert into `employee`(`name`, `birthday`, `gender`, `salary`, `branch_id`, `buddy_id`) values('Herry', '2000/12/19', 'M', 35000, 3, null);
insert into `employee`(`name`, `birthday`, `gender`, `salary`, `branch_id`, `buddy_id`) values('Eve', '1997/1/22', 'F', 47000, 1, 206);
insert into `employee`(`name`, `birthday`, `gender`, `salary`, `branch_id`, `buddy_id`) values('John', '1990/11/10', 'M', 68000, 3, 208);

update `branch`
set `manager_id` = 206
where `branch_id` = 1;
update `branch`
set `manager_id` = 207
where `branch_id` = 2;
update `branch`
set `manager_id` = 208
where `branch_id` = 3;

insert into `client` values(400, 'Apple', '3412');
insert into `client` values(401, 'Banana', '55688');
insert into `client` values(402, 'Candy', '4022');
insert into `client` values(403, 'Dino', '34157');
insert into `client` values(404, 'ETE', '8864');

insert into `works_with` values(206, 400, 70000);
insert into `works_with` values(207, 401, 24000);
insert into `works_with` values(208, 400, 10000);
insert into `works_with` values(208, 403, 24000);
insert into `works_with` values(210, 404, 88000);

