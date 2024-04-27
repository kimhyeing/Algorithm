select a.animal_id, a.animal_type, a.name
from animal_ins as a join animal_outs as b
    on a.animal_id = b.animal_id
where (a.sex_upon_intake like "Intact%") and (b.SEX_UPON_OUTCOME like "Neutered%" or b.SEX_UPON_OUTCOME like "Spayed%")
order by a.animal_id