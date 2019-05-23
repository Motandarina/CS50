# SQLite Music

## Questions

2.1. In the table called Album, why is ArtistId said to be a "foreign key"?
    ArtistID is referencing field from table Artist

2.2. no need for redudancy.Each Album have one Artist mostly,be one Artist can have many album,It is better to put ArtistID in table Album

2.3. customerID canbe foreign key of other tables. It is better to use id than email because for situation of  huge data, more storage is saved

2.4.
select total(Total) from invoice where substr(InvoiceDate,1,4)='2010';
select total(Total) from invoice where strftime('%Y',InvoiceDate)='2010';
SELECT SUM(Total) FROM Invoice WHERE InvoiceDate BETWEEN '2010-01-01' AND '2010-12-31'

2.5.
Select name from track t inner join
    (Select trackid from invoice i inner join
    invoiceline l on i.InvoiceId=l.InvoiceId where CustomerId='50') n
    where t.trackid=n.trackid ;
SELECT Track.Name FROM Invoice JOIN
    InvoiceLine ON Invoice.InvoiceId = InvoiceLine.InvoiceId JOIN
    Track ON InvoiceLine.TrackId = Track.TrackId WHERE CustomerId = 50
2.6. Update track set composer =(select artistid from artist  where track.composer=artist.name );

## Debrief

a. TODO

b. TODO minutes
