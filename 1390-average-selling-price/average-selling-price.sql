# Write your MySQL query statement below
-- s.purchase_date BETWEEN p.start_date AND p.end_date
--             is equivalen to
-- ON p.product_id = s.product_id
-- AND s.purchase_date >= p.start_date
-- AND s.purchase_date <= p.end_date


select p.product_id ,
    round(
    ifnull(sum(p.price*s.units)/sum(s.units),0),2)
    as average_price
from Prices p
left join UnitsSold s
on p.product_id = s.product_id
and s.purchase_date between p.start_date and p.end_date
group by p.product_id
