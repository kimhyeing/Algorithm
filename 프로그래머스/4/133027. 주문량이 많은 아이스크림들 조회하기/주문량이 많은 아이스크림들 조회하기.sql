with all_table as (select flavor, sum(total_order) as total_order
from july
group by flavor
union
select flavor, sum(total_order) as total_order
from first_half
group by flavor)

select flavor
from all_table
group by flavor
order by sum(total_order) desc
limit 3
