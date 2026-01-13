# Write your MySQL query statement below
-- The key concept to remember:
-- If a value comes from another table and must be the same for all groups,
-- you must fetch it using a subquery.

select c.customer_id
from Customer c
group by c.customer_id
having count(distinct c.product_key) = (
    select count(*) from Product #since it is a pk
);