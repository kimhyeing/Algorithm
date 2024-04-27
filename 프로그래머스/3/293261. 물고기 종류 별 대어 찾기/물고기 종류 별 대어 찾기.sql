select a.id as id, b.fish_name as fish_name, a.length as length
from (select id, fish_type, length
        from fish_info
        where (fish_type, length) in (select FISH_TYPE, max(LENGTH) as length
            from fish_info
            group by fish_type)) as a join fish_name_info as b
        on a.fish_type = b.fish_type
order by id
