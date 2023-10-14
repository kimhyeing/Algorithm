select year(b.sales_date) as y, month(b.sales_date) as m, count(distinct b.user_id), 
    round(count(distinct b.user_id)/(select count(distinct user_info.user_id)
                              from user_info
                              where year(user_info.joined) = 2021
                              group by year(user_info.joined)),1)
from user_info as a join online_sale as b
on a.user_id = b.user_id
where year(a.joined) = 2021
group by y, m
order by m

