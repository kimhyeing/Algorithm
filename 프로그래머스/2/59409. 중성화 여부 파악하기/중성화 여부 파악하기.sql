select animal_id, name, (case when SEX_UPON_INTAKE like "%Neutered%" or SEX_UPON_INTAKE like "%Spayed%" then "O"
                        else "X"
                        end) as "중성화"
from ANIMAL_INS
order by animal_id