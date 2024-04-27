select t.year, t.month, count(distinct t.user_id) as PUCHASED_USERS, round(count(distinct t.user_id)/avg(c.all_users), 1)
from
    (select a.user_id, b.sales_amount, year(b.sales_date) as year, month(b.sales_date) as month
    from (select user_id
        from user_info
        where year(joined)=2021) as a join online_sale as b
        on a.user_id = b.user_id) as t, 
        (select count(distinct user_id) as all_users
        from user_info
        where year(joined)=2021) as c
group by t.year, t.month
order by t.year, t.month
    
