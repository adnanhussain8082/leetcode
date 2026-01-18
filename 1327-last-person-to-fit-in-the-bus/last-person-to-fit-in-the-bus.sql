# Write your MySQL query statement below

#using join
-- select q1.person_name
-- from Queue q1
-- inner join Queue q2
-- on q1.turn >= q2.turn
-- group by q1.turn
-- having sum(q2.weight) <=1000
-- order by sum(q2.weight) desc
-- limit 1 

#using window function
select person_name
from (
    select
        person_name,
        sum(weight) over(order by turn) as total_weights
    from Queue
) t
where t.total_weights <= 1000
order by t.total_weights desc
limit 1
