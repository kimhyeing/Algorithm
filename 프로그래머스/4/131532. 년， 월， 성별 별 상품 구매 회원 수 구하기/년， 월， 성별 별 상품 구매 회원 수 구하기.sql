-- 코드를 입력하세요
SELECT year(b.sales_date) as year, month(b.sales_date) as month, a.gender as gender, count(distinct a.user_id)
from user_info as a join online_sale as b
on a.user_id = b.user_id
where a.gender is not null
group by year, month, gender
order by year, month, gender