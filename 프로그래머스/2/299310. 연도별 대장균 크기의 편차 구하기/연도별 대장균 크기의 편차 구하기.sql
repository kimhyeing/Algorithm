-- 코드를 작성해주세요
select b.year as YEAR, (c.max_size-b.SIZE_OF_COLONY) as YEAR_DEV, b.id as ID
from (select year(DIFFERENTIATION_DATE) as year, ID, SIZE_OF_COLONY
        from ECOLI_DATA) as b
        join
        (select a.year as year, max(a.SIZE_OF_COLONY) as max_size
        from (select year(DIFFERENTIATION_DATE) as year, ID, SIZE_OF_COLONY
            from ECOLI_DATA) as a
        group by a.year) as c
    on b.year = c.year
order by YEAR, YEAR_DEV

        
