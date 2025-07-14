# Write your MySQL query statement below
-- select  * from Colume Name

-- CREATE TABLE person(
--     id INT PRIMARY KEY,
--     email VARCHAR (50),
--     GROUP BY email,
--     HAVING COUNT(*)>1;

-- )
SELECT email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;

