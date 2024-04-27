select a.flavor
from (select * from FIRST_HALF union all select * from july) as a
group by a.flavor
order by sum(a.total_order) desc
limit 3