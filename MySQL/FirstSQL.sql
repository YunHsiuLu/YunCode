SHOW DATABASES;
USE `sql_tutorial`;
SHOW TABLES;
CREATE TABLE `student`(
	`student_id` INT PRIMARY KEY,
    `name` VARCHAR(20),
    `major` VARCHAR(20),
    `score` INT
);

INSERT INTO `student` VALUES(1,'Alex','Math',90);
INSERT INTO `student` VALUES(2,'Bob','Math',80);
INSERT INTO `student` VALUES(3,'Catty','Math',85);
INSERT INTO `student` VALUES(4,'Dore','Math',40);
INSERT INTO `student` VALUES(5,'Eve','Math',100);
INSERT INTO `student` VALUES(6,'Fred','Math',100);

#DELETE FROM `student`;

#SELECT * FROM `student`;
#SELECT `student_id`,`major` FROM `student`;
SELECT * FROM `student`
WHERE `student_id` <> 3;


