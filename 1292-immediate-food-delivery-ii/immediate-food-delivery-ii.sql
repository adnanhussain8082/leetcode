# Write your MySQL query statement below
select 
    round(
        sum(d.order_date = d.customer_pref_delivery_date)*100/
        count(distinct d.customer_id)
        ,2
    ) as immediate_percentage
from Delivery d
where (d.customer_id , d.order_date) in (
    select customer_id , min(order_date)
    from Delivery
    group by customer_id
);