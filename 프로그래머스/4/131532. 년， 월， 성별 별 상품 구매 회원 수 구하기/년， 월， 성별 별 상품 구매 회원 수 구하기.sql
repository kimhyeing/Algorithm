select b.year, b.month, a.gender, count(distinct a.user_id) as USERS
from (select user_id, gender from user_info where gender is not null) as a join
    (select user_id, year(SALES_DATE) as year, month(SALES_DATE) as month from online_sale) as b
    on a.user_id = b.user_id
group by b.year, b.month, a.gender
order by b.year, b.month, a.gender