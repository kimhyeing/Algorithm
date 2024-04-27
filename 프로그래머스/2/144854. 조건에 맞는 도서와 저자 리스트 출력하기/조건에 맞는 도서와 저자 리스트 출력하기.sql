select b.book_id, a.author_name, date_format(b.PUBLISHED_DATE, "%Y-%m-%d") as PUBLISHED_DATE
from book as b join author as a
    on b.AUTHOR_ID = a.AUTHOR_ID
where b.category = '경제'
order by PUBLISHED_DATE