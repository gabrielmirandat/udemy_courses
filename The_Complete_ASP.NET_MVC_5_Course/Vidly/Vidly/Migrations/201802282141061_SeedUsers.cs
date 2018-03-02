namespace Vidly.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class SeedUsers : DbMigration
    {
        public override void Up()
        {
            Sql(@"
                INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'a52b7a83-09fe-41e9-becc-dd6ba8cfd7a1', N'guest@vidly.com', 0, N'AFus8k+xNG2t5sJV3/6h6DeCxdT8wzITX8fC/4yTCeFtVJPIMsaEP4Y9dlvq9iuYWg==', N'07fca43e-27b0-46be-b3e4-037dc3222c61', NULL, 0, 0, NULL, 1, 0, N'guest@vidly.com')
                INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'd39ccae6-b407-4a2c-9b47-cfddeed1f7a2', N'admin@vidly.com', 0, N'AA2vuJDIDEw9L63+jSECj0OFTAdZ33O1umlcfwOcH2a7Yb3AFR++Uyt1eBFRbirqBg==', N'424478e8-c887-40a7-9b19-bb3c7f2dfa23', NULL, 0, 0, NULL, 1, 0, N'admin@vidly.com')
                INSERT INTO [dbo].[AspNetRoles] ([Id], [Name]) VALUES (N'af707455-a5be-4fc6-8647-9c1388cb9607', N'CanManageMovies')
                INSERT INTO [dbo].[AspNetUserRoles] ([UserId], [RoleId]) VALUES (N'd39ccae6-b407-4a2c-9b47-cfddeed1f7a2', N'af707455-a5be-4fc6-8647-9c1388cb9607')
            ");
        }
        
        public override void Down()
        {
        }
    }
}
