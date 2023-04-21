// 数据库访问有关的基类
class IDBConnection {
 public:
  virtual ~IDBConnection() {}
};

class IDBCommand {
 public:
  virtual ~IDBCommand() {}
};

class IDataReader {
 public:
  virtual ~IDataReader() {}
};

class IDBConnectionFactory {
 public:
  virtual IDBConnection* createDBConnection() = 0;

  virtual ~IDBConnectionFactory() {}
};

class IDBCommandFactory {
 public:
  virtual IDBCommand* createDBCommand() = 0;

  virtual ~IDBCommandFactory() {}
};

class IDataReaderFactory {
 public:
  virtual IDataReader* createDataReader() = 0;

  virtual ~IDataReaderFactory() {}
};

// 支持 SQL Server
class SqlConnection : public IDBConnection {
};

class SqlCommand : public IDBCommand {
};

class SqlDataReader : public IDataReader {
};

class SqlConnectionFactory : public IDBConnectionFactory {
 public:
  IDBConnection* createDBConnection() override {
    return new SqlConnection();
  }
};

class SqlCommandFactory : public IDBCommandFactory {
 public:
  IDBCommand* createDBCommand() override {
    return new SqlCommand();
  }
};

class SqlDataReaderFactory : public IDataReaderFactory {
 public:
  IDataReader* createDataReader() override {
    return new SqlDataReader();
  }
};

// 支持 Oracle
class OracleConnection : public IDBConnection {
};

class OracleCommand : public IDBCommand {
};

class OracleDataReader : public IDataReader {
};

class OracleConnectionFactory : public IDBConnectionFactory {
 public:
  IDBConnection* createDBConnection() override {
    return new OracleConnection();
  }
};

class OracleCommandFactory : public IDBCommandFactory {
 public:
  IDBCommand* createDBCommand() override {
    return new racleCommand();
  }
};

class OracleDataReaderFactory : public IDataReaderFactory {
 public:
  IDataReader* createDataReader() override {
    return new OracleDataReader();
  }
};

class EmployeeDAO {
  IDBCommandFactory* db_command_factory_;
  IDBConnectionFactory* db_connection_factory_;
  IDataReaderFactory* data_reader_factory_;

 public:
  EmployeeDAO(IDBCommandFactory* command_factory,
              IDBConnectionFactory* connection_factory,
              IDataReaderFactory* data_reader_factory)
      : db_command_factory_(command_factory),
        db_connection_factory_(connection_factory),
        data_reader_factory_(data_reader_factory) {}

  vector<EmployeeDO> GetEmployees() {
    IDBConnection* connection = db_connection_factory_->createDBConnection();
    connection->ConnectionString = "...";

    IDBCommand* command = db_command_factory_->createDBCommand();
    command->CommandText = "...";
    command->SetConnection(connection);

    IDataReader* reader = command->ExecuteReader();
    while (reader->Read()){

    }
  }
};
