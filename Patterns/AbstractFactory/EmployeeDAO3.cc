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

class IDBFactory {
 public:
  virtual IDBConnection* createDBConnection() = 0;
  virtual IDBCommand* createDBCommand() = 0;
  virtual IDataReader* createDataReader() = 0;

  virtual ~IDBConnectionFactory() {}
};

// 支持 SQL Server
class SqlConnection : public IDBConnection {
};

class SqlCommand : public IDBCommand {
};

class SqlDataReader : public IDataReader {
};

class ISqlFactory : public IDBFactory {
 public:
  IDBConnection* createDBConnection() override {
    return new SqlConnection();
  }

  IDBCommand* createDBCommand() override {
    return new SqlCommand();
  }

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

class IOracleFactory : public IDBFactory {
 public:
  IDBConnection* createDBConnection() override {
    return new OracleConnection();
  }

  IDBCommand* createDBCommand() override {
    return new OracleCommand();
  }

  IDataReader* createDataReader() override {
    return new OracleDataReader();
  }
};

class EmployeeDAO {
  IDBFactory* db_factory_;

 public:
  EmployeeDAO(IDBFactory* db_factory)
      : db_factory_(db_factory) {}

  vector<EmployeeDO> GetEmployees() {
    IDBConnection* connection = db_factory_->createDBConnection();
    connection->ConnectionString = "...";

    IDBCommand* command = db_factory_->createDBCommand();
    command->CommandText = "...";
    command->SetConnection(connection);

    IDataReader* reader = command->ExecuteReader();
    while (reader->Read()){

    }
  }
};
