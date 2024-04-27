select a.animal_id, a.name
from ANIMAL_INS as a join ANIMAL_OUTS as b
     on a.animal_id = b.animal_id
where a.datetime > b.datetime
order by a.datetime