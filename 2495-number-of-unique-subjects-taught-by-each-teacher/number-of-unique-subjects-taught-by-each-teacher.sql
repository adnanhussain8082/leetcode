# Write your MySQL query statement below
select teacher_id,
    count(distinct t.subject_id)
    as cnt
from Teacher t
group by t.teacher_id;