select a.pg*10000 as price_group, count(a.pg) as products
from (select *, truncate(price/10000, 0) as pg from product) as a
group by a.pg
order by a.pg
