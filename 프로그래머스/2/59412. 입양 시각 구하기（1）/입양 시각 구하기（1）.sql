-- 코드를 입력하세요
select hour, count(hour)
from (SELECT DATE_FORMAT(datetime, "%H") as hour
    from animal_outs) hour_animal
where hour>=9 and hour<=20
group by hour
order by hour asc

