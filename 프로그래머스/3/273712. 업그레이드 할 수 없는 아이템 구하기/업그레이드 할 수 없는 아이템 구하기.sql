select a.item_id, b.item_name, b.rarity
from (select item_id
    from item_tree
    where item_id not in (select distinct parent_item_id as item_id
                         from item_tree
                         where parent_item_id is not null)) as a
    join item_info b
    on a.item_id = b.item_id
order by a.item_id desc
                     