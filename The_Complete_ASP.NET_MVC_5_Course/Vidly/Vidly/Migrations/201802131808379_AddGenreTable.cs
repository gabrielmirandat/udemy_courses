namespace Vidly.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddGenreTable : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Genres",
                c => new
                    {
                        Id = c.Byte(nullable: false),
                        Name = c.String(nullable: false, maxLength: 32),
                    })
                .PrimaryKey(t => t.Id);
            
            AddColumn("dbo.Movies", "Genre_Id", c => c.Byte());
            AddColumn("dbo.Movies", "GenreId_Id", c => c.Byte());
            CreateIndex("dbo.Movies", "Genre_Id");
            CreateIndex("dbo.Movies", "GenreId_Id");
            AddForeignKey("dbo.Movies", "Genre_Id", "dbo.Genres", "Id");
            AddForeignKey("dbo.Movies", "GenreId_Id", "dbo.Genres", "Id");
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Movies", "GenreId_Id", "dbo.Genres");
            DropForeignKey("dbo.Movies", "Genre_Id", "dbo.Genres");
            DropIndex("dbo.Movies", new[] { "GenreId_Id" });
            DropIndex("dbo.Movies", new[] { "Genre_Id" });
            DropColumn("dbo.Movies", "GenreId_Id");
            DropColumn("dbo.Movies", "Genre_Id");
            DropTable("dbo.Genres");
        }
    }
}
