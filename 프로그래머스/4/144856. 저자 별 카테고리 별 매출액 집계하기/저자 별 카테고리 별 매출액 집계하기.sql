-- 코드를 입력하세요
select author.author_id, author.author_name, book_all.category, sum(book_all.sales*book_all.price) as total_sales
from author join (select book.book_id, book.category, book.author_id, book.price, book_sales.sales_date, book_sales.sales
    from book join book_sales
    on book.book_id = book_sales.book_id
    where book_sales.sales_date >= '2022-01-01' and book_sales.sales_date < '2022-02-01') as book_all
on author.author_id = book_all.author_id
group by author_name, category
order by author.author_id, book_all.category desc

