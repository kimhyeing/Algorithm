-- 코드를 입력하세요
select a.product_id, b.product_name, (a.total_amount*b.PRICE) as TOTAL_SALES
from (select product_id, sum(amount) as total_amount
    from food_order
    where year(PRODUCE_DATE) = 2022 and month(PRODUCE_DATE) = 5
    group by product_id) as a join food_product as b
    on a.product_id = b.product_id
order by total_sales desc, a.product_id
