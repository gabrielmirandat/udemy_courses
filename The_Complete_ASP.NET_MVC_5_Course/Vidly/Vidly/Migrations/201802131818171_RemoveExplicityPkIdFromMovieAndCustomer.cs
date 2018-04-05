namespace Vidly.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class RemoveExplicityPkIdFromMovieAndCustomer : DbMigration
    {
        public override void Up()
        {
            DropForeignKey("dbo.Customers", "MembershipTypeId_Id", "dbo.MembershipTypes");
            DropForeignKey("dbo.Movies", "GenreId_Id", "dbo.Genres");
            DropIndex("dbo.Customers", new[] { "MembershipTypeId_Id" });
            DropIndex("dbo.Movies", new[] { "GenreId_Id" });
            DropColumn("dbo.Customers", "MembershipTypeId_Id");
            DropColumn("dbo.Movies", "GenreId_Id");
        }
        
        public override void Down()
        {
            AddColumn("dbo.Movies", "GenreId_Id", c => c.Byte());
            AddColumn("dbo.Customers", "MembershipTypeId_Id", c => c.Byte());
            CreateIndex("dbo.Movies", "GenreId_Id");
            CreateIndex("dbo.Customers", "MembershipTypeId_Id");
            AddForeignKey("dbo.Movies", "GenreId_Id", "dbo.Genres", "Id");
            AddForeignKey("dbo.Customers", "MembershipTypeId_Id", "dbo.MembershipTypes", "Id");
        }
    }
}
