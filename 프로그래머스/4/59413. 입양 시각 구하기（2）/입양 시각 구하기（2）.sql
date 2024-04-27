with recursive hours as(
    select 0 as hour
    union all
    select hour+1
    from hours
    where hour < 23
)

select b.hour, count(a.animal_id) as count
from (select animal_id, hour(DATETIME) as hour from animal_outs) as a
    right join hours as b
    on a.hour = b.hour
group by b.hour
order by b.hour