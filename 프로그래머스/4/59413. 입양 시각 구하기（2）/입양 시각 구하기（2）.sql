-- 코드를 입력하세요
with recursive entire as (
    select 0 as n
    union all
    select n+1
    from entire
    where n < 23
)

select entire.n, ifnull(c, 0)
from entire left join ( SELECT hour(datetime) as h, count(animal_id) as c
                        from animal_outs
                        group by h
                        order by h ) a
on entire.n = a.h
order by entire.n