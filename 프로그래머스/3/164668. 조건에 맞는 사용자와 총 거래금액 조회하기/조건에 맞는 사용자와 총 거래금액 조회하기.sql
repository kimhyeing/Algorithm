-- 코드를 입력하세요
select a.user_id, b.nickname, sum(a.price) as total_sales
from (SELECT WRITER_ID as user_id, price
    from USED_GOODS_BOARD
    where status = 'DONE') as a join USED_GOODS_USER as b
    on a.user_id = b.user_id
group by a.user_id
having total_sales >= 700000
order by total_sales