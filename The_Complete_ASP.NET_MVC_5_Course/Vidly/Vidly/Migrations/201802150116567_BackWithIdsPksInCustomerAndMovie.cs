namespace Vidly.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class BackWithIdsPksInCustomerAndMovie : DbMigration
    {
        public override void Up()
        {
            RenameColumn(table: "dbo.Customers", name: "MembershipType_Id", newName: "MembershipTypeId");
            RenameColumn(table: "dbo.Movies", name: "Genre_Id", newName: "GenreId");
            RenameIndex(table: "dbo.Customers", name: "IX_MembershipType_Id", newName: "IX_MembershipTypeId");
            RenameIndex(table: "dbo.Movies", name: "IX_Genre_Id", newName: "IX_GenreId");
        }
        
        public override void Down()
        {
            RenameIndex(table: "dbo.Movies", name: "IX_GenreId", newName: "IX_Genre_Id");
            RenameIndex(table: "dbo.Customers", name: "IX_MembershipTypeId", newName: "IX_MembershipType_Id");
            RenameColumn(table: "dbo.Movies", name: "GenreId", newName: "Genre_Id");
            RenameColumn(table: "dbo.Customers", name: "MembershipTypeId", newName: "MembershipType_Id");
        }
    }
}
