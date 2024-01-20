#SHOW DATABASES;
#CREATE DATABASE `exercise1`;
#USE `exercise1`;
CREATE TABLE `Employee`(
	`emp_id` INT PRIMARY KEY,
    `name` VARCHAR(20),
    `birth_date` DATE,
    `sex` VARCHAR(1),
    `salary` INT,
    `branch_id` INT,
    `sup_id` INT
);
CREATE TABLE `Branch`(
	`branch_id` INT PRIMARY KEY,
    `branch_name` VARCHAR(20),
    `manager_id` INT,
    FOREIGN KEY (`manager_id`) REFERENCES `Employee`(`emp_id`)
    ON DELETE SET NULL
);
CREATE TABLE `Client`(
	`client_id` INT PRIMARY KEY,
    `client_name` VARCHAR(20),
    `phone` VARCHAR(50)
);
CREATE TABLE `Works_With`(
	`emp_id` INT,
    `client_id` INT,
    `total_sales` INT,
    PRIMARY KEY(`emp_id`,`client_id`),
    FOREIGN KEY (`emp_id`) REFERENCES `Employee`(`emp_id`) ON DELETE CASCADE,
    FOREIGN KEY (`client_id`) REFERENCES `Client`(`client_id`) ON DELETE CASCADE
);

ALTER TABLE `employee`
ADD FOREIGN KEY (`branch_id`)
REFERENCES `Branch`(`branch_id`)
ON DELETE SET NULL;

ALTER TABLE `employee`
ADD FOREIGN KEY (`sup_id`)
REFERENCES `Employee`(`emp_id`)
ON DELETE SET NULL;

# 新增資料
INSERT INTO `Branch` VALUES(1,'研發',NULL);
INSERT INTO `Branch` VALUES(2,'行政',NULL);
INSERT INTO `Branch` VALUES(3,'資訊',NULL);

INSERT INTO `Employee` VALUES(206,'小黃','1998-10-08','F',50000,1,NULL);
INSERT INTO `Employee` VALUES(207,'小綠','1985-09-16','M',29000,2,206);
INSERT INTO `Employee` VALUES(208,'小黑','2000-12-19','M',35000,3,206);
INSERT INTO `Employee` VALUES(209,'小白','1997-01-22','F',39000,3,207);
INSERT INTO `Employee` VALUES(210,'小藍','1925-11-10','F',84000,1,207);

UPDATE `Branch`
SET `manager_id` = 208
WHERE `branch_id` = 3;

INSERT INTO `Client` VALUES(400,'阿狗',23738473);
INSERT INTO `Client` VALUES(401,'阿貓',23749283);
INSERT INTO `Client` VALUES(402,'阿兔',29184875);
INSERT INTO `Client` VALUES(403,'阿牛',29857885);
INSERT INTO `Client` VALUES(404,'阿虎',29364018);

INSERT INTO `Works_With` VALUES(206,400,70000);
INSERT INTO `Works_With` VALUES(207,401,24000);
INSERT INTO `Works_With` VALUES(208,400,9800);
INSERT INTO `Works_With` VALUES(209,403,24000);
INSERT INTO `Works_With` VALUES(210,404,88000);

