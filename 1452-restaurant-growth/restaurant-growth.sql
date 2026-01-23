# Write your MySQL query statement below
with daily as (
    select
        visited_on,
        sum(amount) as daily_amount
    from Customer
    group by visited_on
),
rolling as (
    select
        visited_on,
        sum(daily_amount) over(
            order by visited_on
            rows between 6 preceding and current row
        ) as amount
    from daily
)

SELECT
    visited_on,
    amount,
    ROUND(amount / 7, 2) AS average_amount
FROM rolling
WHERE visited_on >= (
    SELECT MIN(visited_on) + INTERVAL 6 DAY
    FROM daily
)
ORDER BY visited_on;