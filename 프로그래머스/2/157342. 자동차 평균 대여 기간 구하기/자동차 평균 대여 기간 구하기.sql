-- 코드를 입력하세요
select *
from
    (select car_id, round(sum(dif)/count(car_id), 1) as average_duration
        from
            (SELECT car_id, datediff(end_date, start_date)+1 as dif
            from car_rental_company_rental_history) temp
     group by car_id) temp_avg
where average_duration >= 7
order by average_duration desc, car_id desc