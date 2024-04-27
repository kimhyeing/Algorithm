-- 코드를 작성해주세요
select a.item_id, a.item_name
from item_info as a join item_tree as b
    on a.item_id = b.item_id
where b.PARENT_ITEM_ID is null
order by a.item_id