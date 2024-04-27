select a.category, a.price as max_price, b.product_name
from (SELECT category, max(price) as price
    from food_product
    where category in ('과자', '국', '김치', '식용유')
    group by category) as a join food_product as b
    on a.category = b.category and a.price = b.price
order by max_price desc

