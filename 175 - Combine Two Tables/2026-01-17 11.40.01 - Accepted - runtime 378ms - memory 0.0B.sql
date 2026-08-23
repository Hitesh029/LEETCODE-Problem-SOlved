# Write your MySQL query statement below
select person.firstName, person.lastname, address.city, address.state
from person
LEFT JOIN address  ON person.personId = address.personId;
