select product_code, floor(avg(price)*sum(sales_amount)) as sales
from product as p join offline_sale as o
    on p.product_id = o.product_id
group by p.product_id, product_code
order by sales desc, product_code