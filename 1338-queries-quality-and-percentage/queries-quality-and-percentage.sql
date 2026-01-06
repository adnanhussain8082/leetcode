# Write your MySQL query statement below
select q.query_name , 
    round(avg(q.rating*1.0/q.position),2) as quality,
    round(sum(q.rating<3)*100/count(*),2) as poor_query_percentage
from Queries q
group by q.query_name