/*
 * Problem: 1045. Customers Who Bought All Products
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/customers-who-bought-all-products/
 * Language: mysql
 * Date: 2026-06-18
 */

SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(product_key)
    FROM Product
);
