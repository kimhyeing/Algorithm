-- 코드를 입력하세요
SELECT book.book_id, author.author_name,DATE_FORMAT(book.published_date, "%Y-%m-%d")
from book left outer join author
on book.author_id = author.author_id
where book.category = '경제'
order by book.published_date asc
