select * from `employee` order by `salary`desc;

select * from `employee` order by `salary` desc limit 3;

select `name` from `employee`;

select distinct `branch_id` from `employee`;

select count(*) from `employee` where `birthday` > '2000/1/1' and `gender` = 'F';

select avg(`salary`) from `employee`;

select * from `client` where `phone` like '34%';

select `name` from `employee` where `birthday` like '%/12/%';

select `name` from `employee` union select `client_name` from `client`;

select `emp_id` as `total_id`, `name` as `total_name` from `employee`
union
select `client_id`, `client_name` from `client`;