select DATE_FORMAT(a.sales_date, "%Y-%m-%d") as sales_date, a.product_id, a.user_id, a.sales_amount
from (select user_id, product_id, sales_amount, sales_date from ONLINE_SALE
union all
select null as user_id, product_id, sales_amount, sales_date from OFFLINE_SALE) as a
where sales_date between "2022-03-01" and "2022-03-31"
order by sales_date, product_id, user_id