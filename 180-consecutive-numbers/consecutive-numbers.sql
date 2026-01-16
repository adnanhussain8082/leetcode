# Write your MySQL query statement below
# we will solve it by 2 methods

#ist method using lead() functions and cte(common table expression) - a sort
#of virtual table
#LEAD() → looks forward
#LAG() → looks backward

-- with cte as (
--     select num,
--     lead(num,1) over() as num1,
--     lead(num,2) over() as num2
--     from Logs
-- )

-- select num as ConsecutiveNums
-- from cte
-- where num=num1 and num=num2




#2nd method more robust not fixed to only 3 consecutives
with run as (
    select num,
    row_number() over(order by id) - row_number() over(partition by num order by id) as grp
    from logs
)

select distinct num as ConsecutiveNums
from run
group by num , grp
having count(*) >= 3
