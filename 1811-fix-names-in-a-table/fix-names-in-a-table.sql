# Write your MySQL query statement below
select
    u.user_id,
    concat(upper(substr(u.name , 1 , 1)) , lower(substr(u.name , 2))) as name
from Users u
order by u.user_id asc