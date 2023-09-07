#include <iostream>
#include "sqlite3.h"

int main() {
    //创建一个数据库对象
    sqlite3 *db = nullptr;
    //打开一个数据库，如果不存在则创建一个数据库
    int ret = sqlite3_open("phi.db", &db);
    if (ret != SQLITE_OK) {
        std::cout << "failed to open database" << std::endl;
        return 0;
    }
    //创建一个表
    std::string sql = "create table if not exists record(_id integer primary key autoincrement, time text, phi1 float, phi2 float, phi3 float, phi4 float, phi5 float, phi6 float)";
    char *errmsg = nullptr;
    ret = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cout << "failed to create table" << std::endl;
        std::cout << errmsg << std::endl;
        sqlite3_close(db);
        return 0;
    }
    //插入数据
    for (int i = 0; i < 3; i++) {
        sql = "insert into record(time, phi1, phi2, phi3, phi4, phi5, phi6) values('2022', 1, 2.2, 3, 4, 5, 6)";
        ret = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
        if (ret != SQLITE_OK) {
            std::cout << "failed to insert data" << std::endl;
            std::cout << errmsg << std::endl;
            sqlite3_close(db);
            return 0;
        }
    }
    //删除_id为1的数据
    sql = "delete from record where _id = 2";
    ret = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cout << "failed to delete data" << std::endl;
        std::cout << errmsg << std::endl;
        sqlite3_close(db);
        return 0;
    }
    //查找phi1为1的数据
    sql = "select * from record where phi1 = 1";
    ret = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
    if (ret != SQLITE_OK) {
        std::cout << "failed to select data" << std::endl;
        std::cout << errmsg << std::endl;
        sqlite3_close(db);
        return 0;
    }
    //遍历查询结果
    std::cout << "id\ttime\tphi1\tphi2\tphi3\tphi4\tphi5\tphi6" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    sqlite3_stmt *stmt = nullptr;
    ret = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (ret != SQLITE_OK) {
        std::cout << "failed to prepare statement" << std::endl;
        std::cout << errmsg << std::endl;
        sqlite3_close(db);
        return 0;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string time = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        float phi1 = sqlite3_column_double(stmt, 2);
        float phi2 = sqlite3_column_double(stmt, 3);
        float phi3 = sqlite3_column_double(stmt, 4);
        float phi4 = sqlite3_column_double(stmt, 5);
        float phi5 = sqlite3_column_double(stmt, 6);
        float phi6 = sqlite3_column_double(stmt, 7);
        std::cout << id << "\t" << time << "\t" << phi1 << "\t" << phi2 << "\t" << phi3 << "\t" << phi4 << "\t" << phi5 << "\t" << phi6 << std::endl;
    }
    sqlite3_close(db);
    return 0;
}
