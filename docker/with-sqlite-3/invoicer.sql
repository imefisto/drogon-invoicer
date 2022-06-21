CREATE TABLE IF NOT EXISTS customers (
    id VARCHAR(38) PRIMARY KEY,
    name VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS invoices (
    invoice_number INT UNSIGNED PRIMARY KEY,
    customer_id VARCHAR(38) NOT NULL,
    total DECIMAL(15,2),
    FOREIGN KEY (customer_id) REFERENCES customers(id)
);

INSERT INTO customers (id, name) VALUES ('id1', "Antonio D. Bain");
INSERT INTO invoices (invoice_number, customer_id, total) VALUES (1, 'id1', 10.50);

INSERT INTO customers (id, name) VALUES ('id2', "Grace R. Shaw");
INSERT INTO invoices (invoice_number, customer_id, total) VALUES (2, 'id2', 34.54);

INSERT INTO customers (id, name) VALUES ('id3', "Emmett Savage");
INSERT INTO invoices (invoice_number, customer_id, total) VALUES (3, 'id3', 23.50);
